#!/usr/bin/env python3
"""
BLE UART Protocol Testing Harness - Startup Script

This script provides an easy way to run the FastAPI application.
"""

import uvicorn
import sys
import os

def main():
    """Main entry point for the application."""
    
    # Check if we're in the right directory
    if not os.path.exists('main.py'):
        print("Error: main.py not found. Please run this script from the project directory.")
        sys.exit(1)
    
    # Default configuration
    host = "127.0.0.1"
    port = 8000
    reload = True
    
    # Parse command line arguments
    if len(sys.argv) > 1:
        if sys.argv[1] == "--help" or sys.argv[1] == "-h":
            print("Usage: python run.py [host] [port] [--no-reload]")
            print("  host: IP address to bind to (default: 127.0.0.1)")
            print("  port: Port to bind to (default: 8000)")
            print("  --no-reload: Disable auto-reload on file changes")
            sys.exit(0)
        
        if len(sys.argv) > 1:
            host = sys.argv[1]
        if len(sys.argv) > 2:
            try:
                port = int(sys.argv[2])
            except ValueError:
                print(f"Error: Invalid port number: {sys.argv[2]}")
                sys.exit(1)
        if "--no-reload" in sys.argv:
            reload = False
    
    print(f"Starting BLE UART Protocol Testing Harness...")
    print(f"Host: {host}")
    print(f"Port: {port}")
    print(f"Auto-reload: {'Enabled' if reload else 'Disabled'}")
    print(f"Web interface: http://{host}:{port}")
    print(f"API documentation: http://{host}:{port}/docs")
    print("\nPress Ctrl+C to stop the server.")
    
    try:
        uvicorn.run(
            "main:app",
            host=host,
            port=port,
            reload=reload,
            log_level="info"
        )
    except KeyboardInterrupt:
        print("\nServer stopped by user.")
    except Exception as e:
        print(f"Error starting server: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
