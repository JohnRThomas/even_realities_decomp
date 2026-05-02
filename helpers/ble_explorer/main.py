from fastapi import FastAPI, Request, HTTPException, Form, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse, RedirectResponse
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from pydantic import BaseModel, Field
from typing import List, Optional, Dict, Any
import json
import os
from pathlib import Path
import asyncio
import logging

# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Import BLE manager after logging setup
from ble_manager import ble_manager

app = FastAPI(title="BLE UART Protocol Testing Harness", version="1.0.0")

@app.on_event("startup")
async def startup_event():
    """Initialize BLE manager on startup and auto-connect to first available device"""
    logger.info("Starting BLE UART Protocol Testing Harness...")
    logger.info("BLE manager initialized")
    
    # Auto-connect to first available device
    try:
        logger.info("Auto-connecting to first available BLE device...")
        devices = await ble_manager.scan_for_devices()
        
        if devices:
            first_device = devices[0]
            logger.info(f"Found device: {first_device.name} ({first_device.address})")
            logger.info("Attempting to connect...")
            
            success = await ble_manager.connect_to_device(first_device)
            if success:
                logger.info(f"Auto-connection successful to {first_device.name}")
                # Start connection maintenance task
                if not ble_manager.connection_task or ble_manager.connection_task.done():
                    ble_manager.connection_task = asyncio.create_task(ble_manager.maintain_connection())
            else:
                logger.warning(f"Auto-connection failed to {first_device.name}")
        else:
            logger.info("No BLE devices found matching 'Even G1_' pattern")
            
    except Exception as e:
        logger.error(f"Auto-connection failed: {e}")
        logger.info("You can manually scan and connect from the BLE Dashboard")

@app.on_event("shutdown")
async def shutdown_event():
    """Clean up BLE manager on shutdown"""
    logger.info("Shutting down BLE UART Protocol Testing Harness...")
    if ble_manager.is_connected:
        await ble_manager.disconnect()
    logger.info("BLE manager cleaned up")

# Mount templates and static files
templates = Jinja2Templates(directory="templates")
app.mount("/static", StaticFiles(directory="static"), name="static")

# Data file path
DATA_FILE = "ble_message_types.json"

# Pydantic models
class Attribute(BaseModel):
    name: str
    width: Optional[int] = None
    is_max_width: bool = False  # True if width represents max width, False if fixed width
    description: Optional[str] = ""
    default_value: Optional[str] = None
    is_computed: bool = False
    computed_from: Optional[str] = None

class MessageType(BaseModel):
    id: str
    name: str
    description: Optional[str] = ""
    attributes: List[Attribute]

class MessageTypeCreate(BaseModel):
    name: str
    description: Optional[str] = ""
    attributes: List[Attribute]

class MessageTypeUpdate(BaseModel):
    name: Optional[str] = None
    description: Optional[str] = None
    attributes: Optional[List[Attribute]] = None

class Message(BaseModel):
    id: str
    message_type_id: str
    name: str
    description: Optional[str] = ""
    values: Dict[str, Any]  # Attribute name -> value mapping
    created_at: Optional[str] = None

class MessageCreate(BaseModel):
    message_type_id: str
    name: str
    description: Optional[str] = ""
    values: Dict[str, Any]

class MessageSequence(BaseModel):
    id: str
    name: str
    description: Optional[str] = ""
    messages: List[Dict[str, Any]]  # List of {message_id: str, delay_ms: int}
    created_at: Optional[str] = None

class MessageSequenceCreate(BaseModel):
    name: str
    description: Optional[str] = ""
    messages: List[Dict[str, Any]]

# Data storage functions
def load_data() -> Dict[str, MessageType]:
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, 'r') as f:
            data = json.load(f)
            return {k: MessageType(**v) for k, v in data.items()}
    return {}

def save_data(data: Dict[str, MessageType]):
    with open(DATA_FILE, 'w') as f:
        json.dump({k: v.model_dump() for k, v in data.items()}, f, indent=2)

def load_messages() -> Dict[str, Message]:
    messages_file = "ble_messages.json"
    if os.path.exists(messages_file):
        with open(messages_file, 'r') as f:
            data = json.load(f)
            return {k: Message(**v) for k, v in data.items()}
    return {}

def save_messages(messages: Dict[str, Message]):
    messages_file = "ble_messages.json"
    with open(messages_file, 'w') as f:
        json.dump({k: v.model_dump() for k, v in messages.items()}, f, indent=2)

def generate_message_id() -> str:
    messages = load_messages()
    counter = len(messages) + 1
    while f"msg_instance_{counter:03d}" in messages:
        counter += 1
    return f"msg_instance_{counter:03d}"

def load_message_sequences() -> Dict[str, MessageSequence]:
    sequences_file = "ble_message_sequences.json"
    if os.path.exists(sequences_file):
        with open(sequences_file, 'r') as f:
            data = json.load(f)
            return {k: MessageSequence(**v) for k, v in data.items()}
    return {}

def save_message_sequences(sequences: Dict[str, MessageSequence]):
    sequences_file = "ble_message_sequences.json"
    with open(sequences_file, 'w') as f:
        json.dump({k: v.model_dump() for k, v in sequences.items()}, f, indent=2)

def generate_sequence_id() -> str:
    sequences = load_message_sequences()
    counter = len(sequences) + 1
    while f"seq_{counter:03d}" in sequences:
        counter += 1
    return f"seq_{counter:03d}"

def validate_attribute_values(values: Dict[str, Any], message_type: MessageType) -> None:
    """Validate that attribute values meet the constraints defined in the message type."""
    for attr in message_type.attributes:
        if attr.name in values:
            value = values[attr.name]
            
            # Convert value to appropriate format for validation
            if isinstance(value, str):
                # Handle hex strings
                if value.startswith('0x'):
                    try:
                        value = int(value, 16)
                    except ValueError:
                        raise ValueError(f"Invalid hex value '{value}' for attribute '{attr.name}'")
                elif value.startswith('\\x'):
                    # Handle escaped hex like \x25
                    try:
                        value = int(value[2:], 16)
                    except ValueError:
                        raise ValueError(f"Invalid escaped hex value '{value}' for attribute '{attr.name}'")
                else:
                    # Try to parse as hex or decimal
                    try:
                        value = int(value, 16)
                    except ValueError:
                        try:
                            value = int(value)
                        except ValueError:
                            # If it's a string, validate length
                            if attr.width:
                                if attr.is_max_width:
                                    # For max width, ensure string length is within limit
                                    if len(value.encode('utf-8')) > attr.width:
                                        raise ValueError(f"String value '{value}' for attribute '{attr.name}' exceeds max width {attr.width} bytes")
                                else:
                                    # For fixed width, ensure exact length
                                    encoded_length = len(value.encode('utf-8'))
                                    if encoded_length != attr.width:
                                        raise ValueError(f"String value '{value}' for attribute '{attr.name}' has length {encoded_length} bytes, but fixed width is {attr.width} bytes")
                            continue  # String validation complete
            
            # Validate numeric values
            if isinstance(value, int) and attr.width:
                if attr.is_max_width:
                    # For max width, ensure value fits
                    max_value = (1 << (attr.width * 8)) - 1
                    if value > max_value:
                        raise ValueError(f"Value {value} for attribute '{attr.name}' exceeds max width {attr.width} bytes (max value: {max_value})")
                    if value < 0:
                        # Check if negative values are allowed for this width
                        min_value = -(1 << (attr.width * 8 - 1))
                        if value < min_value:
                            raise ValueError(f"Value {value} for attribute '{attr.name}' is below minimum for {attr.width} bytes (min value: {min_value})")
                else:
                    # For fixed width, ensure value fits exactly
                    max_value = (1 << (attr.width * 8)) - 1
                    if value > max_value:
                        raise ValueError(f"Value {value} for attribute '{attr.name}' exceeds fixed width {attr.width} bytes (max value: {max_value})")
                    if value < 0:
                        # Check if negative values are allowed for this width
                        min_value = -(1 << (attr.width * 8 - 1))
                        if value < min_value:
                            raise ValueError(f"Value {value} for attribute '{attr.name}' is below minimum for {attr.width} bytes (min value: {min_value})")
            
            # Validate byte values
            elif isinstance(value, bytes) and attr.width:
                if attr.is_max_width:
                    # For max width, ensure bytes fit
                    if len(value) > attr.width:
                        raise ValueError(f"Byte value for attribute '{attr.name}' has length {len(value)} bytes, but max width is {attr.width} bytes")
                else:
                    # For fixed width, ensure exact length
                    if len(value) != attr.width:
                        raise ValueError(f"Byte value for attribute '{attr.name}' has length {len(value)} bytes, but fixed width is {attr.width} bytes")

def serialize_message(message: Message, message_type: MessageType) -> bytes:
    """Serialize a message to bytes based on its message type definition."""
    result = bytearray()
    
    for attr in message_type.attributes:
        if attr.name in message.values:
            value = message.values[attr.name]
            
            # Convert value to appropriate format
            if isinstance(value, str):
                # Handle hex strings
                if value.startswith('0x'):
                    value = int(value, 16)
                elif value.startswith('\\x'):
                    # Handle escaped hex like \x25
                    value = int(value[2:], 16)
                else:
                    # Try to parse as hex or decimal
                    try:
                        value = int(value, 16)
                    except ValueError:
                        try:
                            value = int(value)
                        except ValueError:
                            # If it's a string, convert to bytes
                            value = value.encode('utf-8')
            
            # Convert to bytes based on width
            if attr.width:
                if isinstance(value, int):
                    if attr.is_max_width:
                        # For max width, ensure value fits within the max width
                        max_value = (1 << (attr.width * 8)) - 1
                        if value > max_value:
                            raise ValueError(f"Value {value} exceeds max width {attr.width} bytes (max value: {max_value})")
                        # For max width, use the minimum bytes needed to represent the value
                        if value == 0:
                            # Special case: 0 needs at least 1 byte
                            min_bytes = 1
                            result.extend(value.to_bytes(min_bytes, byteorder='big'))
                        else:
                            # Calculate minimum bytes needed
                            min_bytes = (value.bit_length() + 7) // 8
                            result.extend(value.to_bytes(min_bytes, byteorder='big'))
                        logger.info(f"Serializing attribute '{attr.name}' with value {value} (int) to {min_bytes} bytes (max width: {attr.width})")
                    else:
                        # Fixed width
                        logger.info(f"Serializing attribute '{attr.name}' with value {value} (int) to {attr.width} bytes (fixed width)")
                        result.extend(value.to_bytes(attr.width, byteorder='big'))
                elif isinstance(value, bytes):
                    if attr.is_max_width:
                        # For max width, use actual data length (truncate if it exceeds max)
                        if len(value) > attr.width:
                            value = value[:attr.width]
                            logger.info(f"Serializing attribute '{attr.name}' with value (bytes) to {len(value)} bytes (truncated from max width: {attr.width})")
                        else:
                            logger.info(f"Serializing attribute '{attr.name}' with value (bytes) to {len(value)} bytes (max width: {attr.width})")
                        result.extend(value)
                    else:
                        # Fixed width - pad or truncate
                        if len(value) < attr.width:
                            value = value + b'\x00' * (attr.width - len(value))
                        elif len(value) > attr.width:
                            value = value[:attr.width]
                        result.extend(value)
    
    return bytes(result)

def generate_id() -> str:
    data = load_data()
    counter = len(data) + 1
    while f"msg_{counter:03d}" in data:
        counter += 1
    return f"msg_{counter:03d}"

# Routes
@app.get("/", response_class=HTMLResponse)
async def home(request: Request):
    data = load_data()
    messages = load_messages()
    message_sequences = load_message_sequences()
    return templates.TemplateResponse("index.html", {
        "request": request, 
        "message_types": [mt.model_dump() for mt in data.values()],
        "messages": [msg.model_dump() for msg in messages.values()],
        "message_sequences": [seq.model_dump() for seq in message_sequences.values()]
    })

@app.get("/message-types/new", response_class=HTMLResponse)
async def new_message_type_form(request: Request):
    return templates.TemplateResponse("message_type_form.html", {"request": request, "message_type": None})

@app.get("/test-form", response_class=HTMLResponse)
async def test_form(request: Request):
    with open("simple_test.html", "r") as f:
        content = f.read()
    return HTMLResponse(content=content)

@app.post("/message-types", response_class=HTMLResponse)
async def create_message_type(
    request: Request,
    name: str = Form(...),
    description: str = Form(""),
    attribute_names: List[str] = Form(...),
    attribute_widths: List[str] = Form(...),
    attribute_descriptions: List[str] = Form(...),
    attribute_default_values: List[str] = Form(...),
    attribute_computed: List[str] = Form(default=[]),
    attribute_computed_from: List[str] = Form(default=[])
):
    # Parse attributes
    attributes = []
    for i, attr_name in enumerate(attribute_names):
        if attr_name.strip():
            width = None
            is_max_width = False
            
            if attribute_widths[i].strip():
                try:
                    width = int(attribute_widths[i])
                except ValueError:
                    pass
            
            # Check if this attribute uses max width
            form_data = await request.form()
            max_width_key = f"attribute_is_max_width_{i}"
            if max_width_key in form_data:
                is_max_width = True
            
            # Check if this attribute is computed by looking for the specific field
            is_computed = False
            computed_from = None
            
            # Look for computed checkbox and computed_from field for this specific index
            form_data = await request.form()
            computed_key = f"attribute_computed_{i}"
            computed_from_key = f"attribute_computed_from_{i}"
            
            if computed_key in form_data:
                is_computed = True
                if computed_from_key in form_data:
                    computed_from = form_data[computed_from_key].strip() if form_data[computed_from_key].strip() else None
            
            attributes.append(Attribute(
                name=attr_name.strip(),
                width=width,
                is_max_width=is_max_width,
                description=attribute_descriptions[i].strip(),
                default_value=attribute_default_values[i].strip() if attribute_default_values[i].strip() else None,
                is_computed=is_computed,
                computed_from=computed_from
            ))
    
    # Ensure first attribute is always "command"
    if not attributes:
        attributes.insert(0, Attribute(name="command", width=1, is_max_width=False, description="Command identifier", default_value=None, is_computed=False, computed_from=None))
    elif attributes[0].name != "command":
        attributes.insert(0, Attribute(name="command", width=1, is_max_width=False, description="Command identifier", default_value=None, is_computed=False, computed_from=None))
    
    message_type = MessageType(
        id=generate_id(),
        name=name,
        description=description,
        attributes=attributes
    )
    
    data = load_data()
    data[message_type.id] = message_type
    save_data(data)
    
    return RedirectResponse(url="/", status_code=303)

@app.get("/message-types/{message_type_id}/edit", response_class=HTMLResponse)
async def edit_message_type_form(request: Request, message_type_id: str):
    data = load_data()
    if message_type_id not in data:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    return templates.TemplateResponse("message_type_form.html", {
        "request": request, 
        "message_type": data[message_type_id].model_dump()
    })

@app.post("/message-types/{message_type_id}", response_class=HTMLResponse)
async def update_message_type(
    request: Request,
    message_type_id: str,
    name: str = Form(...),
    description: str = Form(""),
    attribute_names: List[str] = Form(...),
    attribute_widths: List[str] = Form(...),
    attribute_descriptions: List[str] = Form(...),
    attribute_default_values: List[str] = Form(...),
    attribute_computed: List[str] = Form(default=[]),
    attribute_computed_from: List[str] = Form(default=[])
):
    data = load_data()
    if message_type_id not in data:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    # Parse attributes (same logic as create)
    attributes = []
    for i, attr_name in enumerate(attribute_names):
        if attr_name.strip():
            width = None
            is_max_width = False
            
            if attribute_widths[i].strip():
                try:
                    width = int(attribute_widths[i])
                except ValueError:
                    pass
            
            # Check if this attribute uses max width
            form_data = await request.form()
            max_width_key = f"attribute_is_max_width_{i}"
            if max_width_key in form_data:
                is_max_width = True
            
            # Check if this attribute is computed by looking for the specific field
            is_computed = False
            computed_from = None
            
            # Look for computed checkbox and computed_from field for this specific index
            form_data = await request.form()
            computed_key = f"attribute_computed_{i}"
            computed_from_key = f"attribute_computed_from_{i}"
            
            if computed_key in form_data:
                is_computed = True
                if computed_from_key in form_data:
                    computed_from = form_data[computed_from_key].strip() if form_data[computed_from_key].strip() else None
            
            attributes.append(Attribute(
                name=attr_name.strip(),
                width=width,
                is_max_width=is_max_width,
                description=attribute_descriptions[i].strip(),
                default_value=attribute_default_values[i].strip() if attribute_default_values[i].strip() else None,
                is_computed=is_computed,
                computed_from=computed_from
            ))
    
    # Ensure first attribute is always "command"
    if not attributes:
        attributes.insert(0, Attribute(name="command", width=1, is_max_width=False, description="Command identifier", default_value=None, is_computed=False, computed_from=None))
    elif attributes[0].name != "command":
        attributes.insert(0, Attribute(name="command", width=1, is_max_width=False, description="Command identifier", default_value=None, is_computed=False, computed_from=None))
    
    data[message_type_id] = MessageType(
        id=message_type_id,
        name=name,
        description=description,
        attributes=attributes
    )
    save_data(data)
    
    return RedirectResponse(url="/", status_code=303)

@app.post("/message-types/{message_type_id}/delete")
async def delete_message_type(message_type_id: str):
    data = load_data()
    if message_type_id not in data:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    del data[message_type_id]
    save_data(data)
    
    return RedirectResponse(url="/", status_code=303)

# Message routes
@app.get("/messages", response_class=HTMLResponse)
async def list_messages(request: Request):
    messages = load_messages()
    message_types = load_data()
    return templates.TemplateResponse("messages.html", {
        "request": request, 
        "messages": messages.values(),
        "message_types": {k: v.model_dump() for k, v in message_types.items()}
    })

@app.get("/messages/new", response_class=HTMLResponse)
async def new_message_form(request: Request):
    message_types = load_data()
    return templates.TemplateResponse("message_form.html", {
        "request": request, 
        "message": None,
        "message_types": {k: v.model_dump() for k, v in message_types.items()}
    })

@app.post("/messages", response_class=HTMLResponse)
async def create_message(
    request: Request,
    message_type_id: str = Form(...),
    name: str = Form(...),
    description: str = Form("")
):
    message_types = load_data()
    if message_type_id not in message_types:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    message_type = message_types[message_type_id]
    
    # Parse attribute values from form
    form_data = await request.form()
    values = {}
    
    for attr in message_type.attributes:
        value_key = f"attribute_value_{attr.name}"
        if value_key in form_data:
            value = form_data[value_key].strip()
            if value:
                # Use default value if provided and no value entered
                if not value and attr.default_value:
                    value = attr.default_value
                values[attr.name] = value
            elif attr.default_value:
                values[attr.name] = attr.default_value
    
    # Validate attribute values
    try:
        validate_attribute_values(values, message_type)
    except ValueError as e:
        raise HTTPException(status_code=400, detail=f"Validation error: {e}")

    message = Message(
        id=generate_message_id(),
        message_type_id=message_type_id,
        name=name,
        description=description,
        values=values
    )
    
    messages = load_messages()
    messages[message.id] = message
    save_messages(messages)
    
    return RedirectResponse(url=f"/messages/{message.id}", status_code=303)

@app.get("/messages/{message_id}", response_class=HTMLResponse)
async def view_message(request: Request, message_id: str):
    messages = load_messages()
    message_types = load_data()
    
    if message_id not in messages:
        raise HTTPException(status_code=404, detail="Message not found")
    
    message = messages[message_id]
    message_type = message_types.get(message.message_type_id)
    
    if not message_type:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    # Serialize the message
    try:
        serialized_bytes = serialize_message(message, message_type)
        hex_string = serialized_bytes.hex()
        escaped_string = ''.join([f'\\x{b:02x}' for b in serialized_bytes])
    except Exception as e:
        logger.error(f"Serialization error for message_id={message_id}: {str(e)}", exc_info=True)
        serialized_bytes = None
        hex_string = f"Error: {str(e)}"
        escaped_string = f"Error: {str(e)}"
    
    return templates.TemplateResponse("message_view.html", {
        "request": request,
        "message": message,
        "message_type": message_type.model_dump(),
        "serialized_bytes": serialized_bytes,
        "hex_string": hex_string,
        "escaped_string": escaped_string
    })

@app.get("/messages/by-name/{message_name}", response_class=HTMLResponse)
async def redirect_message_by_name(message_name: str):
    """Redirect to a message page by searching for the message name"""
    messages = load_messages()
    
    # Find the first message with a matching name
    for message_id, message in messages.items():
        if message.name == message_name:
            return RedirectResponse(url=f"/messages/{message_id}", status_code=303)
    
    # If no message found with that name, raise 404
    raise HTTPException(status_code=404, detail=f"No message found with name '{message_name}'")

@app.get("/messages/{message_id}/edit", response_class=HTMLResponse)
async def edit_message_form(request: Request, message_id: str):
    messages = load_messages()
    message_types = load_data()
    
    if message_id not in messages:
        raise HTTPException(status_code=404, detail="Message not found")
    
    message = messages[message_id]
    
    return templates.TemplateResponse("message_form.html", {
        "request": request,
        "message": message,
        "message_types": {k: v.model_dump() for k, v in message_types.items()}
    })

@app.post("/messages/{message_id}", response_class=HTMLResponse)
async def update_message(
    request: Request,
    message_id: str,
    message_type_id: str = Form(...),
    name: str = Form(...),
    description: str = Form("")
):
    messages = load_messages()
    message_types = load_data()
    
    if message_id not in messages:
        raise HTTPException(status_code=404, detail="Message not found")
    
    if message_type_id not in message_types:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    message_type = message_types[message_type_id]
    
    # Parse attribute values from form
    form_data = await request.form()
    values = {}
    
    for attr in message_type.attributes:
        value_key = f"attribute_value_{attr.name}"
        if value_key in form_data:
            value = form_data[value_key].strip()
            if value:
                # Use default value if provided and no value entered
                if not value and attr.default_value:
                    value = attr.default_value
                values[attr.name] = value
            elif attr.default_value:
                values[attr.name] = attr.default_value
    
    # Validate attribute values
    try:
        validate_attribute_values(values, message_type)
    except ValueError as e:
        raise HTTPException(status_code=400, detail=f"Validation error: {e}")

    messages[message_id] = Message(
        id=message_id,
        message_type_id=message_type_id,
        name=name,
        description=description,
        values=values
    )
    save_messages(messages)
    
    return RedirectResponse(url=f"/messages/{message_id}", status_code=303)

@app.post("/messages/{message_id}/delete")
async def delete_message(message_id: str):
    messages = load_messages()
    if message_id not in messages:
        raise HTTPException(status_code=404, detail="Message not found")
    
    del messages[message_id]
    save_messages(messages)
    
    return RedirectResponse(url="/messages", status_code=303)

# MessageSequence routes
@app.get("/message-sequences", response_class=HTMLResponse)
async def list_message_sequences(request: Request):
    sequences = load_message_sequences()
    messages = load_messages()
    message_types = load_data()
    return templates.TemplateResponse("message_sequences.html", {
        "request": request, 
        "sequences": sequences.values(),
        "messages": {k: v.model_dump() for k, v in messages.items()},
        "message_types": {k: v.model_dump() for k, v in message_types.items()}
    })

@app.get("/message-sequences/new", response_class=HTMLResponse)
async def new_message_sequence_form(request: Request):
    messages = load_messages()
    message_types = load_data()
    return templates.TemplateResponse("message_sequence_form.html", {
        "request": request, 
        "sequence": None,
        "messages": {k: v.model_dump() for k, v in messages.items()},
        "message_types": {k: v.model_dump() for k, v in message_types.items()}
    })

@app.post("/message-sequences", response_class=HTMLResponse)
async def create_message_sequence(
    request: Request,
    name: str = Form(...),
    description: str = Form(""),
    message_ids: List[str] = Form(...),
    delays: List[str] = Form(...)
):
    # Parse message sequence data
    messages = []
    for i, message_id in enumerate(message_ids):
        if message_id.strip():
            delay = 1000  # Default 1 second
            if i < len(delays) and delays[i].strip():
                try:
                    delay = int(delays[i])
                except ValueError:
                    delay = 1000
            
            messages.append({
                "message_id": message_id.strip(),
                "delay_ms": delay
            })
    
    sequence = MessageSequence(
        id=generate_sequence_id(),
        name=name,
        description=description,
        messages=messages
    )
    
    sequences = load_message_sequences()
    sequences[sequence.id] = sequence
    save_message_sequences(sequences)
    
    return RedirectResponse(url="/message-sequences", status_code=303)

@app.get("/message-sequences/{sequence_id}", response_class=HTMLResponse)
async def view_message_sequence(request: Request, sequence_id: str):
    sequences = load_message_sequences()
    messages = load_messages()
    message_types = load_data()
    
    if sequence_id not in sequences:
        raise HTTPException(status_code=404, detail="Message sequence not found")
    
    sequence = sequences[sequence_id]
    
    # Get full message details for each message in the sequence
    sequence_messages = []
    total_duration = 0
    
    for msg_info in sequence.messages:
        message_id = msg_info["message_id"]
        delay_ms = msg_info["delay_ms"]
        
        if message_id in messages:
            message = messages[message_id]
            message_type = message_types.get(message.message_type_id)
            
            # Serialize the message
            try:
                serialized_bytes = serialize_message(message, message_type)
                hex_string = serialized_bytes.hex()
                escaped_string = ''.join([f'\\x{b:02x}' for b in serialized_bytes])
            except Exception as e:
                hex_string = f"Error: {str(e)}"
                escaped_string = f"Error: {str(e)}"
                serialized_bytes = None
            
            sequence_messages.append({
                "message": message.model_dump(),
                "message_type": message_type.model_dump(),
                "delay_ms": delay_ms,
                "hex_string": hex_string,
                "escaped_string": escaped_string,
                "serialized_bytes": serialized_bytes
            })
            
            total_duration += delay_ms
    
    return templates.TemplateResponse("message_sequence_view.html", {
        "request": request,
        "sequence": sequence.model_dump(),
        "sequence_messages": sequence_messages,
        "total_duration": total_duration
    })

@app.get("/message-sequences/{sequence_id}/edit", response_class=HTMLResponse)
async def edit_message_sequence_form(request: Request, sequence_id: str):
    sequences = load_message_sequences()
    messages = load_messages()
    message_types = load_data()
    
    if sequence_id not in sequences:
        raise HTTPException(status_code=404, detail="Message sequence not found")
    
    sequence = sequences[sequence_id]
    
    return templates.TemplateResponse("message_sequence_form.html", {
        "request": request,
        "sequence": sequence.model_dump(),
        "messages": {k: v.model_dump() for k, v in messages.items()},
        "message_types": {k: v.model_dump() for k, v in message_types.items()}
    })

@app.post("/message-sequences/{sequence_id}", response_class=HTMLResponse)
async def update_message_sequence(
    request: Request,
    sequence_id: str,
    name: str = Form(...),
    description: str = Form(""),
    message_ids: List[str] = Form(...),
    delays: List[str] = Form(...)
):
    sequences = load_message_sequences()
    
    if sequence_id not in sequences:
        raise HTTPException(status_code=404, detail="Message sequence not found")
    
    # Parse message sequence data
    messages = []
    for i, message_id in enumerate(message_ids):
        if message_id.strip():
            delay = 1000  # Default 1 second
            if i < len(delays) and delays[i].strip():
                try:
                    delay = int(delays[i])
                except ValueError:
                    delay = 1000
            
            messages.append({
                "message_id": message_id.strip(),
                "delay_ms": delay
            })
    
    sequences[sequence_id] = MessageSequence(
        id=sequence_id,
        name=name,
        description=description,
        messages=messages
    )
    save_message_sequences(sequences)
    
    return RedirectResponse(url="/message-sequences", status_code=303)

@app.post("/message-sequences/{sequence_id}/delete")
async def delete_message_sequence(sequence_id: str):
    sequences = load_message_sequences()
    if sequence_id not in sequences:
        raise HTTPException(status_code=404, detail="Message sequence not found")
    
    del sequences[sequence_id]
    save_message_sequences(sequences)
    
    return RedirectResponse(url="/message-sequences", status_code=303)

@app.get("/ble-dashboard")
async def ble_dashboard(request: Request):
    return templates.TemplateResponse("ble_dashboard.html", {"request": request})

# API endpoints for programmatic access
@app.get("/api/message-types")
async def get_message_types():
    return load_data()

@app.get("/api/message-types/{message_type_id}")
async def get_message_type(message_type_id: str):
    data = load_data()
    if message_type_id not in data:
        raise HTTPException(status_code=404, detail="Message type not found")
    return data[message_type_id]

@app.get("/api/messages")
async def get_messages():
    return load_messages()

@app.get("/api/messages/{message_id}")
async def get_message(message_id: str):
    messages = load_messages()
    if message_id not in messages:
        raise HTTPException(status_code=404, detail="Message not found")
    return messages[message_id]

@app.get("/api/messages/{message_id}/serialize")
async def serialize_message_api(message_id: str):
    messages = load_messages()
    message_types = load_data()
    
    if message_id not in messages:
        raise HTTPException(status_code=404, detail="Message not found")
    
    message = messages[message_id]
    message_type = message_types.get(message.message_type_id)
    
    if not message_type:
        raise HTTPException(status_code=404, detail="Message type not found")
    
    try:
        serialized_bytes = serialize_message(message, message_type)
        return {
            "message_id": message_id,
            "hex": serialized_bytes.hex(),
            "escaped": ''.join([f'\\x{b:02x}' for b in serialized_bytes]),
            "length": len(serialized_bytes)
        }
    except Exception as e:
        import traceback
        tb_str = traceback.format_exc()
        logger.error(f"Serialization error for message_id={message_id}: {str(e)}\n{tb_str}")
        raise HTTPException(status_code=400, detail=f"Serialization error: {str(e)}\n{tb_str}")

@app.get("/api/message-sequences")
async def get_message_sequences():
    return load_message_sequences()

@app.get("/api/message-sequences/{sequence_id}")
async def get_message_sequence(sequence_id: str):
    sequences = load_message_sequences()
    if sequence_id not in sequences:
        raise HTTPException(status_code=404, detail="Message sequence not found")
    return sequences[sequence_id]

@app.get("/api/message-sequences/{sequence_id}/serialize")
async def serialize_message_sequence_api(sequence_id: str):
    sequences = load_message_sequences()
    messages = load_messages()
    message_types = load_data()
    
    if sequence_id not in sequences:
        raise HTTPException(status_code=404, detail="Message sequence not found")
    
    sequence = sequences[sequence_id]
    result = []
    
    for msg_info in sequence.messages:
        message_id = msg_info["message_id"]
        delay_ms = msg_info["delay_ms"]
        
        if message_id in messages:
            message = messages[message_id]
            message_type = message_types.get(message.message_type_id)
            
            try:
                serialized_bytes = serialize_message(message, message_type)
                result.append({
                    "message_id": message_id,
                    "message_name": message.name,
                    "delay_ms": delay_ms,
                    "hex": serialized_bytes.hex(),
                    "escaped": ''.join([f'\\x{b:02x}' for b in serialized_bytes]),
                    "length": len(serialized_bytes)
                })
            except Exception as e:
                result.append({
                    "message_id": message_id,
                    "message_name": message.name,
                    "delay_ms": delay_ms,
                    "error": str(e)
                })
    
    return {
        "sequence_id": sequence_id,
        "sequence_name": sequence.name,
        "total_duration_ms": sum(msg["delay_ms"] for msg in sequence.messages),
        "messages": result
    }

# BLE Device Management
@app.get("/api/ble/scan")
async def scan_for_devices():
    """Scan for BLE devices matching '_R_' pattern"""
    try:
        devices = await ble_manager.scan_for_devices()
        return {
            "devices": [
                {
                    "name": device.name,
                    "address": device.address,
                    "rssi": getattr(device, 'rssi', None)
                }
                for device in devices
            ]
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Scan failed: {str(e)}")

@app.post("/api/ble/connect")
async def connect_to_device(device_address: str = Form(...)):
    """Connect to a specific BLE device"""
    try:
        logger.info(f"Connect request received for device: {device_address}")
        
        # Find the device by address
        devices = await ble_manager.scan_for_devices()
        target_device = None
        for device in devices:
            if device.address == device_address:
                target_device = device
                break
        
        if not target_device:
            logger.warning(f"Device {device_address} not found in scan results")
            raise HTTPException(status_code=404, detail="Device not found")
        
        # Connect to the device
        success = await ble_manager.connect_to_device(target_device)
        if success:
            # Start connection maintenance task
            if not ble_manager.connection_task or ble_manager.connection_task.done():
                ble_manager.connection_task = asyncio.create_task(ble_manager.maintain_connection())
            
            logger.info(f"Successfully connected to {target_device.name}")
            return {"status": "connected", "device": target_device.name}
        else:
            logger.error(f"Failed to connect to device {target_device.name}")
            raise HTTPException(status_code=500, detail="Failed to connect to device")
            
    except Exception as e:
        logger.error(f"Connection failed: {str(e)}")
        raise HTTPException(status_code=500, detail=f"Connection failed: {str(e)}")

@app.get("/api/ble/status")
async def get_ble_status():
    """Get current BLE connection status"""
    logger.info(f"BLE Status Request - is_connected: {ble_manager.is_connected}")
    logger.info(f"BLE Status Request - target_device: {ble_manager.target_device}")
    logger.info(f"BLE Status Request - client: {ble_manager.client}")
    
    return {
        "is_connected": ble_manager.is_connected,
        "device_name": ble_manager.target_device.name if ble_manager.target_device else None,
        "device_address": ble_manager.target_device.address if ble_manager.target_device else None
    }

@app.post("/api/ble/disconnect")
async def disconnect_device():
    """Disconnect from current device"""
    try:
        await ble_manager.disconnect()
        return {"status": "disconnected"}
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Disconnect failed: {str(e)}")

# Message Execution
@app.post("/api/messages/{message_id}/run")
async def run_message(message_id: str):
    """Execute a single message"""
    try:
        if not ble_manager.is_connected:
            raise HTTPException(status_code=400, detail="Not connected to any device")
        
        # Get the message
        messages = load_messages()
        if message_id not in messages:
            raise HTTPException(status_code=404, detail="Message not found")
        
        message = messages[message_id]
        message_types = load_data()
        message_type = message_types.get(message.message_type_id)
        
        if not message_type:
            raise HTTPException(status_code=404, detail="Message type not found")
        
        # Serialize the message
        serialized_bytes = serialize_message(message, message_type)
        
        # Send the message
        sent_id = await ble_manager.send_message(
            data=serialized_bytes,
            message_name=message.name
        )
        
        return {
            "status": "sent",
            "message_id": message_id,
            "sent_id": sent_id,
            "hex_data": serialized_bytes.hex()
        }
        
    except Exception as e:
        print(e)
        raise HTTPException(status_code=500, detail=f"Failed to run message: {str(e)}")

@app.post("/api/message-sequences/{sequence_id}/run")
async def run_message_sequence(sequence_id: str):
    """Execute a message sequence"""
    try:
        if not ble_manager.is_connected:
            raise HTTPException(status_code=400, detail="Not connected to any device")
        
        # Get the sequence
        sequences = load_message_sequences()
        if sequence_id not in sequences:
            raise HTTPException(status_code=404, detail="Message sequence not found")
        
        sequence = sequences[sequence_id]
        messages = load_messages()
        message_types = load_data()
        
        # Prepare messages for sending
        sequence_messages = []
        for msg_info in sequence.messages:
            message_id = msg_info["message_id"]
            if message_id in messages:
                message = messages[message_id]
                message_type = message_types.get(message.message_type_id)
                
                if message_type:
                    try:
                        serialized_bytes = serialize_message(message, message_type)
                        sequence_messages.append({
                            "hex": serialized_bytes.hex(),
                            "message_name": message.name,
                            "delay_ms": msg_info["delay_ms"]
                        })
                    except Exception as e:
                        logger.error(f"Failed to serialize message {message_id}: {e}")
        
        if not sequence_messages:
            raise HTTPException(status_code=400, detail="No valid messages in sequence")
        
        # Send the sequence
        sent_ids = await ble_manager.send_message_sequence(
            messages=sequence_messages,
            sequence_name=sequence.name
        )
        
        return {
            "status": "sequence_sent",
            "sequence_id": sequence_id,
            "sent_count": len(sent_ids),
            "sent_ids": sent_ids
        }
        
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Failed to run sequence: {str(e)}")

@app.get("/api/ble/communication-log")
async def get_communication_log():
    """Get the BLE communication log"""
    return ble_manager.get_communication_log()

@app.post("/api/ble/clear-log")
async def clear_communication_log():
    """Clear the BLE communication log"""
    try:
        # Clear the communication log in the BLE manager
        ble_manager.clear_communication_log()
        logger.info("Communication log cleared via API")
        
        return {"status": "cleared", "message": "Communication log cleared successfully"}
        
    except Exception as e:
        logger.error(f"Failed to clear communication log: {str(e)}")
        raise HTTPException(status_code=500, detail=f"Failed to clear communication log: {str(e)}")

@app.post("/api/ble/send-custom")
async def send_custom_message(request: Request):
    """Send a custom hexadecimal message to the connected BLE device"""
    try:
        if not ble_manager.is_connected:
            raise HTTPException(status_code=400, detail="Not connected to any device")
        
        # Parse the request body
        body = await request.json()
        hex_data = body.get("hex_data")
        message_name = body.get("message_name", "Custom Message")
        
        if not hex_data:
            raise HTTPException(status_code=400, detail="hex_data is required")
        
        # Validate hexadecimal format
        try:
            # Remove any spaces and convert to bytes
            clean_hex = hex_data.replace(" ", "")
            if len(clean_hex) % 2 != 0:
                raise ValueError("Hex string must have even number of characters")
            
            data = bytes.fromhex(clean_hex)
        except ValueError as e:
            raise HTTPException(status_code=400, detail=f"Invalid hexadecimal format: {str(e)}")
        
        # Send the custom message
        sent_id = await ble_manager.send_message(
            data=data,
            message_name=message_name
        )
        
        return {
            "status": "sent",
            "sent_id": sent_id,
            "hex_data": hex_data,
            "message_name": message_name
        }
        
    except Exception as e:
        logger.error(f"Failed to send custom message: {str(e)}")
        raise HTTPException(status_code=500, detail=f"Failed to send custom message: {str(e)}")

# WebSocket endpoint for real-time updates
@app.websocket("/ws/ble")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    try:
        while True:
            # Send current communication log
            log_data = ble_manager.get_communication_log()
            await websocket.send_text(json.dumps({
                "type": "communication_log",
                "data": log_data
            }))
            
            # Send connection status
            status_data = {
                "type": "connection_status",
                "data": {
                    "is_connected": ble_manager.is_connected,
                    "device_name": ble_manager.target_device.name if ble_manager.target_device else None,
                    "device_address": ble_manager.target_device.address if ble_manager.target_device else None
                }
            }
            await websocket.send_text(json.dumps(status_data))
            
            # Wait before sending next update
            await asyncio.sleep(1)
            
    except WebSocketDisconnect:
        logger.info("WebSocket client disconnected")
    except Exception as e:
        logger.error(f"WebSocket error: {e}")

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, port=8000)
