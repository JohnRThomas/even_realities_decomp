// BLE UART Protocol Testing Harness - Main JavaScript

document.addEventListener('DOMContentLoaded', function() {
    // Initialize tooltips
    initializeTooltips();
    
    // Initialize form validation
    initializeFormValidation();
    
    // Add smooth scrolling
    addSmoothScrolling();
    
    // Add keyboard shortcuts
    addKeyboardShortcuts();
});

function initializeTooltips() {
    // Initialize Bootstrap tooltips if available
    if (typeof bootstrap !== 'undefined' && bootstrap.Tooltip) {
        const tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'));
        tooltipTriggerList.map(function (tooltipTriggerEl) {
            return new bootstrap.Tooltip(tooltipTriggerEl);
        });
    }
}

function initializeFormValidation() {
    const forms = document.querySelectorAll('.needs-validation');
    
    forms.forEach(form => {
        form.addEventListener('submit', function(event) {
            if (!form.checkValidity()) {
                event.preventDefault();
                event.stopPropagation();
            }
            form.classList.add('was-validated');
        });
    });
}

function addSmoothScrolling() {
    // Smooth scroll to top when clicking on navbar brand
    const navbarBrand = document.querySelector('.navbar-brand');
    if (navbarBrand) {
        navbarBrand.addEventListener('click', function(e) {
            e.preventDefault();
            window.scrollTo({
                top: 0,
                behavior: 'smooth'
            });
        });
    }
}

function addKeyboardShortcuts() {
    // Ctrl/Cmd + N for new message type
    document.addEventListener('keydown', function(e) {
        if ((e.ctrlKey || e.metaKey) && e.key === 'n') {
            e.preventDefault();
            const newButton = document.querySelector('a[href="/message-types/new"]');
            if (newButton) {
                newButton.click();
            }
        }
        
        // Ctrl/Cmd + / for search focus (if we add search later)
        if ((e.ctrlKey || e.metaKey) && e.key === '/') {
            e.preventDefault();
            const searchInput = document.querySelector('input[type="search"]');
            if (searchInput) {
                searchInput.focus();
            }
        }
    });
}

// Utility function to show notifications
function showNotification(message, type = 'info', duration = 3000) {
    // Remove existing notifications
    const existingNotifications = document.querySelectorAll('.notification-toast');
    existingNotifications.forEach(notification => notification.remove());
    
    // Create notification element
    const notification = document.createElement('div');
    notification.className = `notification-toast alert alert-${type} alert-dismissible fade show`;
    notification.style.cssText = `
        position: fixed;
        top: 20px;
        right: 20px;
        z-index: 9999;
        min-width: 300px;
        box-shadow: 0 4px 12px rgba(0, 0, 0, 0.15);
        border-radius: 8px;
        border: none;
    `;
    
    notification.innerHTML = `
        ${message}
        <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
    `;
    
    // Add to page
    document.body.appendChild(notification);
    
    // Auto-remove after duration
    setTimeout(() => {
        if (notification.parentNode) {
            notification.remove();
        }
    }, duration);
    
    // Add click to dismiss
    notification.addEventListener('click', function() {
        notification.remove();
    });
}

// Utility function to format bytes
function formatBytes(bytes, decimals = 2) {
    if (bytes === 0) return '0 Bytes';
    
    const k = 1024;
    const dm = decimals < 0 ? 0 : decimals;
    const sizes = ['Bytes', 'KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'];
    
    const i = Math.floor(Math.log(bytes) / Math.log(k));
    
    return parseFloat((bytes / Math.pow(k, i)).toFixed(dm)) + ' ' + sizes[i];
}

// Utility function to validate hex strings
function isValidHex(str) {
    return /^[0-9A-Fa-f]+$/.test(str);
}

// Utility function to convert hex to bytes
function hexToBytes(hex) {
    const bytes = [];
    for (let i = 0; i < hex.length; i += 2) {
        bytes.push(parseInt(hex.substr(i, 2), 16));
    }
    return bytes;
}

// Utility function to convert bytes to hex
function bytesToHex(bytes) {
    return bytes.map(byte => byte.toString(16).padStart(2, '0')).join('');
}

// Enhanced form handling for dynamic attributes
function enhanceAttributeForm() {
    const container = document.getElementById('attributesContainer');
    if (!container) return;
    
    // Add drag and drop reordering for attributes
    let draggedElement = null;
    
    container.addEventListener('dragstart', function(e) {
        if (e.target.classList.contains('attribute-row')) {
            draggedElement = e.target;
            e.target.style.opacity = '0.5';
        }
    });
    
    container.addEventListener('dragend', function(e) {
        if (e.target.classList.contains('attribute-row')) {
            e.target.style.opacity = '1';
        }
    });
    
    container.addEventListener('dragover', function(e) {
        e.preventDefault();
        const afterElement = getDragAfterElement(container, e.clientY);
        if (draggedElement && afterElement) {
            container.insertBefore(draggedElement, afterElement);
        }
    });
    
    // Make attribute rows draggable
    const attributeRows = container.querySelectorAll('.attribute-row');
    attributeRows.forEach(row => {
        if (!row.querySelector('input[readonly]')) { // Don't make command attribute draggable
            row.draggable = true;
            row.style.cursor = 'grab';
        }
    });
}

function getDragAfterElement(container, y) {
    const draggableElements = [...container.querySelectorAll('.attribute-row:not([draggable="false"])')];
    
    return draggableElements.reduce((closest, child) => {
        const box = child.getBoundingClientRect();
        const offset = y - box.top - box.height / 2;
        
        if (offset < 0 && offset > closest.offset) {
            return { offset: offset, element: child };
        } else {
            return closest;
        }
    }, { offset: Number.NEGATIVE_INFINITY }).element;
}

// Auto-save functionality for forms
function initializeAutoSave() {
    const forms = document.querySelectorAll('form');
    
    forms.forEach(form => {
        const inputs = form.querySelectorAll('input, textarea, select');
        let autoSaveTimer;
        
        inputs.forEach(input => {
            input.addEventListener('input', function() {
                clearTimeout(autoSaveTimer);
                autoSaveTimer = setTimeout(() => {
                    // Save form data to localStorage
                    const formData = new FormData(form);
                    const formObject = {};
                    for (let [key, value] of formData.entries()) {
                        if (!formObject[key]) {
                            formObject[key] = [];
                        }
                        formObject[key].push(value);
                    }
                    localStorage.setItem('form_autosave', JSON.stringify(formObject));
                }, 1000); // Auto-save after 1 second of inactivity
            });
        });
    });
}

// Export functionality for message types
function exportMessageTypes() {
    fetch('/api/message-types')
        .then(response => response.json())
        .then(data => {
            const dataStr = JSON.stringify(data, null, 2);
            const dataBlob = new Blob([dataStr], {type: 'application/json'});
            const url = URL.createObjectURL(dataBlob);
            const link = document.createElement('a');
            link.href = url;
            link.download = 'ble_message_types.json';
            link.click();
            URL.revokeObjectURL(url);
        })
        .catch(error => {
            console.error('Error exporting message types:', error);
            showNotification('Error exporting message types', 'danger');
        });
}

// Import functionality for message types
function importMessageTypes() {
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = '.json';
    
    input.onchange = function(e) {
        const file = e.target.files[0];
        if (file) {
            const reader = new FileReader();
            reader.onload = function(e) {
                try {
                    const data = JSON.parse(e.target.result);
                    // Here you would typically send the data to the server
                    // For now, just show a notification
                    showNotification(`Imported ${Object.keys(data).length} message types`, 'success');
                } catch (error) {
                    showNotification('Invalid JSON file', 'danger');
                }
            };
            reader.readAsText(file);
        }
    };
    
    input.click();
}

// Initialize enhanced features when DOM is ready
document.addEventListener('DOMContentLoaded', function() {
    enhanceAttributeForm();
    initializeAutoSave();
    
    // Add export/import buttons if they don't exist
    const header = document.querySelector('.d-flex.justify-content-between.align-items-center.mb-4');
    if (header && !document.querySelector('.export-import-buttons')) {
        const buttonGroup = document.createElement('div');
        buttonGroup.className = 'export-import-buttons btn-group';
        buttonGroup.innerHTML = `
            <button type="button" class="btn btn-outline-secondary btn-sm" onclick="exportMessageTypes()" title="Export Message Types">
                <i class="fas fa-download"></i>
            </button>
            <button type="button" class="btn btn-outline-secondary btn-sm" onclick="importMessageTypes()" title="Import Message Types">
                <i class="fas fa-upload"></i>
            </button>
        `;
        header.appendChild(buttonGroup);
    }
});
