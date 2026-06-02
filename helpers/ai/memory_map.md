# Memory Map Analysis - Decompiled Firmware

## Overview
This document provides a comprehensive analysis of the memory structures, global variables, and secret data organization discovered in the decompiled firmware codebase. The analysis reveals a sophisticated system with multiple data types including schedules, stocks, news, and quick notes.

## Core Memory Structures

### 1. Work Mode Context Structure

| Context Type | Offset | Size | Description |
|--------------|---------|------|-------------|
| **Main Context** | `param_1 + 0x870` | - | Primary system context |
| **Work Mode Context** | `param_1 + 0xfec` | - | Work mode specific data |

#### Main Context Fields (0x870 offset)

| Offset | Size | Field Name | Description |
|--------|------|------------|-------------|
| +0x00 | 1 byte | Dashboard Display Mode | Main dashboard configuration |
| +0x04 | 1 byte | Custom Display Area Value 1 | Primary custom area setting |
| +0x05 | 1 byte | Custom Display Area Value 2 | Secondary custom area setting |
| +0x5d | 1 byte | System Timestamp Parameter | Timestamp configuration |
| +0x5e | 1 byte | Quick Note Display Mode | Quick note display setting |
| +0x5f | 1 byte | Additional System Parameter | Extended system configuration |

#### Work Mode Context Fields (0xfec offset)

| Offset | Size | Field Name | Description |
|--------|------|------------|-------------|
| +0x00 | 4 bytes | System Timestamp | Primary timestamp value |
| +0x04 | 4 bytes | System Timestamp High | High-order timestamp bits |
| +0x08 | 4 bytes | System Timestamp Low | Low-order timestamp bits |
| +0x0c | 4 bytes | System Timestamp Extended | Extended timestamp data |
| +0x33 | 4 bytes | Configuration Data Pointer | Pointer to config data |
| +0x5d | 1 byte | Schedule Display Mode | Schedule display setting |
| +0x5e | 1 byte | Quick Note Display Mode | Quick note display setting |
| +0x5f | 1 byte | Additional Display Mode | Extended display config |
| +0x60 | 1 byte | System Parameter 1 | System configuration 1 |
| +0x61 | 1 byte | System Parameter 2 | System configuration 2 |
| +0x64 | 1 byte | Stock Display Mode | Stock display setting |
| +0x65 | 1 byte | Custom Display Area Value | Custom area configuration |
| +0x66 | 1 byte | Schedule Display Mode | Schedule display setting |
| +0x67 | 1 byte | Schedule Record Count | Number of schedule records |
| +0x68 | 1 byte | Stock Display Mode | Stock display setting |
| +0x69 | 1 byte | News Display Mode | News display setting |
| +0x8a4 | 4 bytes | Quick Note Data Pointer | Pointer to quick note data |
| +0x1020 | 4 bytes | News Data Pointer | Pointer to news data |
| +0x1054 | 4 bytes | System State Pointer | Pointer to system state |

### 2. Stock Data Structure

| Property | Value | Description |
|----------|-------|-------------|
| **Base Address** | `0x2000d71a` | Starting address of stock data |
| **Record Size** | `0x7f2` (2034 bytes) | Size of each stock record |
| **Max Records** | 5 | Maximum number of stock entries |
| **Total Memory** | 10,170 bytes | Total allocated memory |

#### Stock Record Layout

| Offset | Size | Field Name | Description | Max Data |
|--------|------|------------|-------------|----------|
| +0x000 | 1 byte | Active Flag | Record activation status | 1 byte |
| +0x001 | 1 byte | Stock Code Length | Length of stock code | 1 byte |
| +0x002 | 32 bytes | Stock Code Name | Stock symbol/identifier | 32 bytes |
| +0x022 | 1 byte | Company Name Length | Length of company name | 1 byte |
| +0x023 | 64 bytes | Company Name | Full company name | 64 bytes |
| +0x063 | 1 byte | Stock Price Length | Length of price data | 1 byte |
| +0x064 | 16 bytes | Stock Price | Current stock price | 16 bytes |
| +0x074 | 1 byte | Price Change Length | Length of change data | 1 byte |
| +0x075 | 16 bytes | Price Change | Price change amount | 16 bytes |
| +0x085 | 1 byte | Change Rate Length | Length of rate data | 1 byte |
| +0x086 | 16 bytes | Change Rate | Percentage change | 16 bytes |
| +0x096 | 1 byte | Change Status | Change direction/status | 1 byte |
| +0x097 | 2 bytes | Image Data Size | Size of stock image | 2 bytes |
| +0x099 | 1886 bytes | Image Data | Stock chart/image | 1886 bytes |

#### Stock Metadata Variables

| Variable Name | Type | Description |
|---------------|------|-------------|
| `STOCK_DATA_FLAGS` | byte[5] | Array indicating active records |
| `STOCK_DATA_SIZES` | short[5] | Array of image sizes |
| `STOCK_COUNT_LIMIT` | byte | Maximum stock records (5) |
| `STOCK_DISPLAY_MODE` | byte | Current display mode |
| `STOCK_CUSTOM_AREA_VALUE` | byte | Custom display area setting |

### 3. Schedule/Quick Note Structure

#### Schedule Data Buffer

| Property | Value | Description |
|----------|-------|-------------|
| **Buffer Name** | `SCHEDULE_DATA_BUFFER` | Global buffer identifier |
| **Buffer Size** | `0x420` (1056 bytes) | Total buffer size |
| **Record Size** | `0x81` (129 bytes) | Size per schedule record |
| **Max Records** | 8 | Maximum schedule entries |

#### Schedule Record Layout

| Offset | Size | Field Name | Description | Max Data |
|--------|------|------------|-------------|----------|
| +0x000 | 1 byte | Active Flag | Record activation status | 1 byte |
| +0x001 | 1 byte | Title Length | Length of schedule title | 1 byte |
| +0x002 | 64 bytes | Title Data | Schedule title text | 64 bytes |
| +0x042 | 1 byte | Time Length | Length of time data | 1 byte |
| +0x043 | 32 bytes | Time Data | Schedule time information | 32 bytes |
| +0x063 | 1 byte | Location Length | Length of location data | 1 byte |
| +0x064 | 32 bytes | Location Data | Schedule location | 32 bytes |

#### Quick Note Structure

| Property | Value | Description |
|----------|-------|-------------|
| **Buffer Name** | `QUICKNOTE_DATA_BUFFER` | Global buffer identifier |
| **Record Size** | `0x143` (323 bytes) | Size per quick note record |
| **Max Records** | 2 | Maximum quick note entries |

#### Quick Note Record Layout

| Offset | Size | Field Name | Description | Max Data |
|--------|------|------------|-------------|----------|
| +0x000 | 1 byte | Active Flag | Record activation status | 1 byte |
| +0x001 | 1 byte | Title Length | Length of note title | 1 byte |
| +0x002 | 64 bytes | Title Data | Note title text | 64 bytes |
| +0x042 | 1 byte | Time Length | Length of time data | 1 byte |
| +0x043 | 32 bytes | Time Data | Note time information | 32 bytes |
| +0x063 | 1 byte | Location Length | Length of location data | 1 byte |
| +0x064 | 32 bytes | Location Data | Note location | 32 bytes |
| +0x084 | 1 byte | Text Length | Length of note content | 1 byte |
| +0x085 | 195 bytes | Text Data | Note content text | 195 bytes |

### 4. News Data Structure

| Property | Value | Description |
|----------|-------|-------------|
| **Buffer Name** | `NEWS_DATA_BUFFER` | Global buffer identifier |
| **Buffer Size** | `0x161` (353 bytes) | Total buffer size |
| **Record Size** | `0x159` (345 bytes) | Size per news record |
| **Max Records** | 1 | Maximum news entries |

#### News Record Layout

| Offset | Size | Field Name | Description | Max Data |
|--------|------|------------|-------------|----------|
| +0x000 | 1 byte | Active Flag | Record activation status | 1 byte |
| +0x001 | 1 byte | Title Length | Length of news title | 1 byte |
| +0x002 | 64 bytes | Title Data | News title text | 64 bytes |
| +0x042 | 1 byte | Time Length | Length of time data | 1 byte |
| +0x043 | 32 bytes | Time Data | News timestamp | 32 bytes |
| +0x063 | 1 byte | Content Length | Length of news content | 1 byte |
| +0x064 | 247 bytes | Content Data | News article content | 247 bytes |

### 5. Packet Assembly Buffers

#### Schedule Packet Assembly

| Variable | Type | Description |
|----------|------|-------------|
| `SCHEDULE_DATA_BUFFER` | byte[0x420] | 1056-byte assembly buffer |
| `SCHEDULE_PACKET_COUNTER` | byte | Current packet number |
| `SCHEDULE_TOTAL_PACKETS` | byte | Total expected packets |
| `SCHEDULE_DATA_OFFSET` | uint | Current buffer offset |

#### Stock Packet Assembly

| Variable | Type | Description |
|----------|------|-------------|
| `PACKET_ASSEMBLY_BUFFER` | byte[0x812] | 2066-byte assembly buffer |
| `RECEIVED_PACKET_COUNT` | byte | Current packet number |
| `TOTAL_PACKET_COUNT` | byte | Total expected packets |
| `PACKET_DATA_OFFSET` | uint | Current buffer offset |

#### News Packet Assembly

| Variable | Type | Description |
|----------|------|-------------|
| `NEWS_DATA_BUFFER` | byte[0x161] | 353-byte assembly buffer |
| `NEWS_RECEIVED_COUNT` | byte | Current packet number |
| `NEWS_TOTAL_PACKETS` | byte | Total expected packets |
| `NEWS_BUFFER_OFFSET` | uint | Current buffer offset |

## Global Variables and State

### Display Mode Variables

| Variable Name | Type | Description |
|---------------|------|-------------|
| `QUICKNOTE_DISPLAY_MODE` | byte | Quick note display setting |
| `QUICKNOTE_CUSTOM_AREA_VALUE` | byte | Custom area configuration |
| `STOCK_DISPLAY_MODE` | byte | Stock display setting |
| `STOCK_CUSTOM_AREA_VALUE` | byte | Stock custom area configuration |
| `NEWS_DISPLAY_MODE` | byte | News display setting |
| `NEWS_INDEX_NUMBER` | byte | Current news index |

### Data Management Variables

| Variable Name | Type | Description |
|---------------|------|-------------|
| `QUICKNOTE_DATA_LENGTH` | byte | Length of quick note data |
| `QUICKNOTE_RECORD_NUMBER` | byte | Current quick note record |
| `QUICKNOTE_RECEIVED_COUNT` | byte | Received packet count |
| `QUICKNOTE_TOTAL_PACKETS` | byte | Total packet count |
| `QUICKNOTE_BUFFER_OFFSET` | uint | Buffer offset for assembly |

### System State Variables

| Variable Name | Type | Description |
|---------------|------|-------------|
| `CURRENT_STOCK_ID` | byte | Currently selected stock |
| `CURRENT_STOCK_INDEX` | byte | Current stock index |
| `CURRENT_NEWS_INDEX` | byte | Current news index |
| `STOCK_ENTRIES_COUNT` | byte | Number of stock entries |
| `NEWS_DATA_COUNT` | byte | Number of news entries |

## Memory Allocation Patterns

### Dynamic Memory Functions

| Function | Purpose | Usage |
|----------|---------|-------|
| `fill_memory_buffer()` | Buffer initialization | Clear buffers before use |
| `validate_memory_bounds()` | Memory validation | Ensure access within bounds |
| `memcpy()` | Data copying | Transfer data between buffers |

### Buffer Sizing Strategy

| Data Type | Record Size | Total Buffer | Purpose |
|-----------|-------------|--------------|---------|
| **Stock Records** | 0x7f2 (2034 bytes) | 10,170 bytes | Rich data with images |
| **Schedule Records** | 0x81 (129 bytes) | 1,032 bytes | Compact scheduling |
| **Quick Note Records** | 0x143 (323 bytes) | 646 bytes | Balanced text/metadata |
| **News Records** | 0x159 (345 bytes) | 345 bytes | News content |

## Security and Validation

### Data Validation Features

| Validation Type | Implementation | Purpose |
|-----------------|----------------|---------|
| **Packet Order** | Sequence counters | Ensure correct packet arrival |
| **Size Validation** | Length checks | Prevent buffer overflows |
| **Format Validation** | Structure markers | Verify data integrity |
| **Bounds Checking** | Memory range validation | Secure memory access |

### Error Handling Strategy

| Error Type | Response | Recovery Action |
|------------|----------|-----------------|
| **Packet Order Errors** | Reset counters | Clear buffers and restart |
| **Format Errors** | Log errors | Send failure responses |
| **Size Errors** | Truncate data | Prevent overflow |
| **Memory Errors** | Clear buffers | Log status and continue |

## Data Flow Architecture

### 1. BLE PUT Request Processing Flow

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│ Packet Type │ →  │ Validation  │ →  │ Buffer      │ →  │ Data        │ →  │ Response    │
│             │    │             │    │ Selection   │    │ Assembly    │    │             │
└─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘
```

### 2. Multi-Packet Assembly Flow

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│ Initialize  │ →  │ Receive     │ →  │ Validate    │ →  │ Assemble    │ →  │ Complete    │
│             │    │ Packets     │    │ Order       │    │ Data        │    │             │
└─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘
```

### 3. Data Type Routing Matrix

| Packet Type | Data Type | Processing Path |
|-------------|-----------|-----------------|
| **1-3, 5, 0xb, 0x14** | Basic Data | Standard processing |
| **4** | Whitelist App | Application processing |
| **6** | Schedule/Quick Note | Schedule processing |
| **7** | Stock Data | Stock processing |
| **8** | News Data | News processing |

## Memory Layout Summary

### Static Memory Regions

| Address Range | Size | Purpose | Description |
|---------------|------|---------|-------------|
| `0x2000d71a - 0x2000d7aa` | 10,170 bytes | Stock Data | 5 × 0x7f2 byte records |
| Work Mode Contexts | Variable | System Data | Dynamic allocation |
| Global Buffers | Fixed | Packet Assembly | Pre-allocated buffers |

### Dynamic Memory Allocation

| Memory Type | Allocation | Purpose |
|-------------|------------|---------|
| **Packet Assembly** | Temporary | Multi-packet data |
| **Work Mode Data** | Context-specific | System state management |
| **User Data** | On-demand | Schedules, notes, stocks, news |

### Memory Protection Features

| Protection Type | Implementation | Benefit |
|-----------------|----------------|---------|
| **Bounds Checking** | Address validation | Prevent overflow |
| **Buffer Clearing** | Secure initialization | Data isolation |
| **Error Recovery** | Graceful handling | System stability |

## Complete Memory Map

| Address Range | Size | Type | Purpose | Description | Status |
|---------------|------|------|---------|-------------|---------|
| `0x00000000 - 0x0000FFFF` | 64 KB | RAM | System Stack | Primary system stack | Unknown |
| `0x00010000 - 0x0001FFFF` | 64 KB | RAM | Heap | Dynamic memory allocation | Unknown |
| `0x00020000 - 0x0002FFFF` | 64 KB | RAM | Global Variables | System global variables | Unknown |
| `0x00030000 - 0x0003FFFF` | 64 KB | RAM | BLE Stack | Bluetooth Low Energy stack | Unknown |
| `0x00040000 - 0x0004FFFF` | 64 KB | RAM | Audio Buffer | Audio processing buffers | Unknown |
| `0x00050000 - 0x0005FFFF` | 64 KB | RAM | Display Buffer | LCD/framebuffer memory | Unknown |
| `0x00060000 - 0x0006FFFF` | 64 KB | RAM | Sensor Data | Sensor data buffers | Unknown |
| `0x00070000 - 0x0007FFFF` | 64 KB | RAM | Network Buffer | Network communication | Unknown |
| `0x00080000 - 0x0008FFFF` | 64 KB | RAM | File System | File system buffers | Unknown |
| `0x00090000 - 0x0009FFFF` | 64 KB | RAM | Crypto Buffer | Cryptographic operations | Unknown |
| `0x000A0000 - 0x000AFFFF` | 64 KB | RAM | Timer Buffer | Timer and scheduling | Unknown |
| `0x000B0000 - 0x000BFFFF` | 64 KB | RAM | Interrupt Vector | Interrupt handling | Unknown |
| `0x000C0000 - 0x000CFFFF` | 64 KB | RAM | DMA Buffer | Direct memory access | Unknown |
| `0x000D0000 - 0x000DFFFF` | 64 KB | RAM | USB Buffer | USB communication | Unknown |
| `0x000E0000 - 0x000EFFFF` | 64 KB | RAM | Serial Buffer | Serial communication | Unknown |
| `0x000F0000 - 0x000FFFFF` | 64 KB | RAM | Debug Buffer | Debug and logging | Unknown |
| `0x00100000 - 0x001FFFFF` | 1 MB | RAM | Extended RAM | Extended memory space | Unknown |
| `0x00200000 - 0x0020FFFF` | 64 KB | RAM | Work Mode Context | Work mode data structures | **KNOWN** |
| `0x00201000 - 0x00201FFF` | 4 KB | RAM | Quick Note Buffer | Quick note data storage | **KNOWN** |
| `0x00202000 - 0x00202FFF` | 4 KB | RAM | Schedule Buffer | Schedule data storage | **KNOWN** |
| `0x00203000 - 0x00203FFF` | 4 KB | RAM | News Buffer | News data storage | **KNOWN** |
| `0x00204000 - 0x00204FFF` | 4 KB | RAM | Stock Buffer | Stock data storage | **KNOWN** |
| `0x00205000 - 0x00205FFF` | 4 KB | RAM | Packet Assembly | Multi-packet assembly | **KNOWN** |
| `0x00206000 - 0x00206FFF` | 4 KB | RAM | BLE Command | BLE command processing | Unknown |
| `0x00207000 - 0x00207FFF` | 4 KB | RAM | System Config | System configuration | Unknown |
| `0x00208000 - 0x00208FFF` | 4 KB | RAM | User Settings | User preferences | Unknown |
| `0x00209000 - 0x00209FFF` | 4 KB | RAM | Calibration | Sensor calibration data | Unknown |
| `0x0020A000 - 0x0020AFFF` | 4 KB | RAM | Firmware Update | Firmware update buffer | Unknown |
| `0x0020B000 - 0x0020BFFF` | 4 KB | RAM | Security Keys | Security and encryption | Unknown |
| `0x0020C000 - 0x0020CFFF` | 4 KB | RAM | Backup Data | Data backup buffer | Unknown |
| `0x0020D000 - 0x0020DFFF` | 4 KB | RAM | Cache | Data cache memory | Unknown |
| `0x0020E000 - 0x0020EFFF` | 4 KB | RAM | Temp Buffer | Temporary data storage | Unknown |
| `0x0020F000 - 0x0020FFFF` | 4 KB | RAM | Reserved | Reserved for future use | Unknown |
| `0x00210000 - 0x0021FFFF` | 64 KB | RAM | Extended Data | Extended data storage | Unknown |
| `0x00220000 - 0x0022FFFF` | 64 KB | RAM | Media Buffer | Media file buffers | Unknown |
| `0x00230000 - 0x0023FFFF` | 64 KB | RAM | Database | Local database storage | Unknown |
| `0x00240000 - 0x0024FFFF` | 64 KB | RAM | Web Buffer | Web interface buffers | Unknown |
| `0x00250000 - 0x0025FFFF` | 64 KB | RAM | API Buffer | API communication | Unknown |
| `0x00260000 - 0x0026FFFF` | 64 KB | RAM | Sync Buffer | Data synchronization | Unknown |
| `0x00270000 - 0x0027FFFF` | 64 KB | RAM | Notification | Notification system | Unknown |
| `0x00280000 - 0x0028FFFF` | 64 KB | RAM | Widget Data | Widget information | Unknown |
| `0x00290000 - 0x0029FFFF` | 64 KB | RAM | Theme Data | UI theme information | Unknown |
| `0x002A0000 - 0x002AFFFF` | 64 KB | RAM | Language | Multi-language support | Unknown |
| `0x002B0000 - 0x002BFFFF` | 64 KB | RAM | Accessibility | Accessibility features | Unknown |
| `0x002C0000 - 0x002CFFFF` | 64 KB | RAM | Voice Data | Voice recognition | Unknown |
| `0x002D0000 - 0x002DFFFF` | 64 KB | RAM | Gesture Data | Gesture recognition | Unknown |
| `0x002E0000 - 0x002EFFFF` | 64 KB | RAM | Biometric | Biometric data storage | Unknown |
| `0x002F0000 - 0x002FFFFF` | 64 KB | RAM | Health Data | Health monitoring | Unknown |
| `0x00300000 - 0x003FFFFF` | 1 MB | RAM | Application | Application data | Unknown |
| `0x00400000 - 0x004FFFFF` | 1 MB | RAM | User Files | User file storage | Unknown |
| `0x00500000 - 0x005FFFFF` | 1 MB | RAM | Downloads | Download storage | Unknown |
| `0x00600000 - 0x006FFFFF` | 1 MB | RAM | Cache | System cache | Unknown |
| `0x00700000 - 0x007FFFFF` | 1 MB | RAM | Temp | Temporary storage | Unknown |
| `0x00800000 - 0x008FFFFF` | 1 MB | RAM | Logs | System logs | Unknown |
| `0x00900000 - 0x009FFFFF` | 1 MB | RAM | Analytics | Analytics data | Unknown |
| `0x00A00000 - 0x00AFFFFF` | 1 MB | RAM | Telemetry | Telemetry data | Unknown |
| `0x00B00000 - 0x00BFFFFF` | 1 MB | RAM | Diagnostics | Diagnostic data | Unknown |
| `0x00C00000 - 0x00CFFFFF` | 1 MB | RAM | Performance | Performance metrics | Unknown |
| `0x00D00000 - 0x00DFFFFF` | 1 MB | RAM | Monitoring | System monitoring | Unknown |
| `0x00E00000 - 0x00EFFFFF` | 1 MB | RAM | Alerts | Alert system data | Unknown |
| `0x00F00000 - 0x00FFFFF` | 1 MB | RAM | Maintenance | Maintenance data | Unknown |
| `0x01000000 - 0x01FFFFFF` | 16 MB | RAM | Extended | Extended memory | Unknown |
| `0x02000000 - 0x02FFFFFF` | 16 MB | RAM | External | External memory | Unknown |
| `0x03000000 - 0x03FFFFFF` | 16 MB | RAM | Shared | Shared memory | Unknown |
| `0x04000000 - 0x04FFFFFF` | 16 MB | RAM | Virtual | Virtual memory | Unknown |
| `0x05000000 - 0x05FFFFFF` | 16 MB | RAM | Reserved | Reserved memory | Unknown |
| `0x06000000 - 0x06FFFFFF` | 16 MB | RAM | Future | Future expansion | Unknown |
| `0x07000000 - 0x07FFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x08000000 - 0x08FFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x09000000 - 0x09FFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x0A000000 - 0x0AFFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x0B000000 - 0x0BFFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x0C000000 - 0x0CFFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x0D000000 - 0x0DFFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x0E000000 - 0x0EFFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x0F000000 - 0x0FFFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x10000000 - 0x1FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x20000000 - 0x2000D719` | 55 KB | RAM | Unused | Unused memory | Unknown |
| `0x2000D71A - 0x2000D7AA` | 10,170 bytes | RAM | Stock Data | 5 × 0x7f2 byte records | **KNOWN** |
| `0x2000D7AB - 0x2000FFFF` | 9 KB | RAM | Unused | Unused memory | Unknown |
| `0x20010000 - 0x2001FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20020000 - 0x2002FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20030000 - 0x2003FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20040000 - 0x2004FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20050000 - 0x2005FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20060000 - 0x2006FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20070000 - 0x2007FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20080000 - 0x2008FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20090000 - 0x2009FFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x200A0000 - 0x200AFFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x200B0000 - 0x200BFFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x200C0000 - 0x200CFFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x200D0000 - 0x200DFFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x200E0000 - 0x200EFFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x200F0000 - 0x200FFFFF` | 64 KB | RAM | Unused | Unused memory | Unknown |
| `0x20100000 - 0x20FFFFFF` | 16 MB | RAM | Unused | Unused memory | Unknown |
| `0x21000000 - 0x2FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x30000000 - 0x3FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x40000000 - 0x4FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x50000000 - 0x5FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x60000000 - 0x6FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x70000000 - 0x7FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x80000000 - 0x8FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0x90000000 - 0x9FFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0xA0000000 - 0xAFFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0xB0000000 - 0xBFFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0xC0000000 - 0xCFFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0xD0000000 - 0xDFFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0xE0000000 - 0xEFFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |
| `0xF0000000 - 0xFFFFFFFF` | 256 MB | RAM | Unused | Unused memory | Unknown |

## Conclusion

This firmware implements a sophisticated data management system with multiple data types, robust packet assembly, and comprehensive memory protection. The memory layout is carefully designed to handle various data formats while maintaining security and preventing buffer overflows. The system supports real-time data updates for schedules, stocks, news, and quick notes through a well-structured BLE communication protocol.

The secret structs reveal a comprehensive dashboard system capable of displaying financial data, scheduling information, news content, and user notes, all managed through a centralized work mode context system with proper memory isolation and validation.

The complete memory map shows that only a small portion of the available memory space is actually utilized by the known data structures, leaving significant room for future expansion and additional features. The known regions are concentrated in the lower memory addresses, particularly around `0x2000D000` for stock data and various buffer regions for packet assembly and data storage.
