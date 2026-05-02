# BLE UART Protocol Testing Harness

A FastAPI-based web application for testing and managing BLE UART protocol message types. This tool allows you to create, read, update, and delete BLE message type definitions with their associated attributes.

## Features

- **Message Type Management**: CRUD operations for BLE message types
- **Attribute Configuration**: Define attributes with fixed width, maximum width, or computed values
- **Command Enforcement**: First attribute is always "command" and cannot be removed
- **Modern Web Interface**: Responsive Bootstrap-based UI with drag-and-drop attribute reordering
- **JSON Storage**: Simple file-based storage using JSON files
- **Export/Import**: Export and import message type definitions
- **API Endpoints**: RESTful API for programmatic access

## Message Type Structure

Each message type consists of:
- **ID**: Auto-generated unique identifier (e.g., `msg_001`)
- **Name**: Human-readable name for the message type
- **Description**: Optional description of the message type's purpose
- **Attributes**: Ordered list of message attributes

### Attribute Properties

Each attribute can have:
- **Name**: Attribute identifier (first is always "command")
- **Width**: Fixed size in bytes (e.g., 1, 2, 4)
- **Max Width**: Maximum size in bytes for variable-length attributes
- **Description**: Optional description of the attribute
- **Default Value**: Optional default value for the attribute
- **Computed**: Whether the attribute value is computed from another attribute
- **Computed From**: Source attribute name for computed values

## Installation

1. **Clone or download** the project files
2. **Install dependencies**:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

### Starting the Application

```bash
python main.py
```

The application will start on `http://localhost:8000`

### Creating Message Types

1. Navigate to the home page
2. Click "New Message Type"
3. Fill in the message type name and description
4. Add attributes:
   - **Command**: Always present, fixed at 1 byte
   - **Additional attributes**: Add as needed with appropriate widths
5. Click "Create Message Type"

### Example Message Types

#### Simple Command
```
Name: Status Request
Attributes:
- command (1 byte) - Command identifier
- device_id (2 bytes) - Target device identifier (default: 0x01)
```

#### Variable Length Message
```
Name: Data Transfer
Attributes:
- command (1 byte) - Command identifier
- length (1 byte) - Data length (computed from data)
- data (variable) - Payload data (max 255 bytes)
```

#### Complex Message
```
Name: Configuration Update
Attributes:
- command (1 byte) - Command identifier
- subcommand (1 byte) - Subcommand type
- param_count (1 byte) - Number of parameters
- param_length (1 byte) - Length of parameter data
- parameters (variable) - Parameter data
- crc (2 bytes) - Checksum
```

## API Endpoints

### GET `/api/message-types`
Retrieve all message types

### GET `/api/message-types/{id}`
Retrieve a specific message type by ID

### Web Interface
- `GET /` - Home page with message type list
- `GET /message-types/new` - Create new message type form
- `GET /message-types/{id}/edit` - Edit existing message type form

## Data Storage

Message types are stored in `ble_message_types.json` in the project directory. The file structure follows this format:

```json
{
  "msg_001": {
    "id": "msg_001",
    "name": "Status Request",
    "description": "Request device status",
    "attributes": [
      {
        "name": "command",
        "width": 1,
        "max_width": null,
        "description": "Command identifier",
        "is_computed": false,
        "computed_from": null
      },
      {
        "name": "device_id",
        "width": 2,
        "max_width": null,
        "description": "Target device identifier",
        "default_value": "0x01",
        "is_computed": false,
        "computed_from": null
      }
    ]
  }
}
```

## Keyboard Shortcuts

- `Ctrl/Cmd + N`: Navigate to new message type form
- `Ctrl/Cmd + /`: Focus search (when implemented)

## Browser Compatibility

- Chrome/Chromium (recommended)
- Firefox
- Safari
- Edge

## Development

### Project Structure
```
decomp_files/
├── main.py                 # FastAPI application
├── requirements.txt        # Python dependencies
├── README.md              # This file
├── templates/             # HTML templates
│   ├── base.html         # Base template
│   ├── index.html        # Home page
│   └── message_type_form.html  # Form for creating/editing
├── static/               # Static assets
│   ├── css/
│   │   └── style.css    # Custom styles
│   └── js/
│       └── app.js       # JavaScript functionality
└── ble_message_types.json # Data storage (created automatically)
```

### Adding New Features

1. **New Routes**: Add to `main.py`
2. **New Templates**: Create in `templates/` directory
3. **New Styles**: Add to `static/css/style.css`
4. **New JavaScript**: Add to `static/js/app.js`

### Testing

The application can be tested using:
- Web browser for UI testing
- HTTP clients (curl, Postman) for API testing
- Automated testing frameworks (pytest) for backend testing

## Future Enhancements

- **Message Instances**: Create actual message instances from message types
- **Validation**: Real-time message validation
- **BLE Integration**: Direct BLE device communication
- **Message Templates**: Pre-defined message type templates
- **Advanced Analytics**: Message flow analysis and statistics
- **Multi-user Support**: User authentication and permissions
- **Database Integration**: Replace JSON storage with proper database

## Troubleshooting

### Common Issues

1. **Port already in use**: Change the port in `main.py` or kill the existing process
2. **Template errors**: Ensure all template files are in the `templates/` directory
3. **Static file issues**: Check that the `static/` directory structure is correct
4. **JSON errors**: Verify the data file format or delete it to start fresh

### Logs

Check the console output for error messages and debugging information.

## License

This project is provided as-is for educational and testing purposes.

## Contributing

Feel free to submit issues, feature requests, or pull requests to improve the application.
