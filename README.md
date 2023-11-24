
# Notification Area
A rust program that uses the windows api to show notifications in the notification area from the rust side using a c ffi through a dll

## Info

Only on Windows

## Installation

Make sure you've installed rust compiler https://www.rust-lang.org/tools/install

After setting up the project 

We update cargo
```bash
cargo update
```

The DLL file was created with the gcc compiler, run this command in the rrot of the project

```bash
gcc -shared -o notification.dll notification.c
```

Build the Rust Executable
```bash
cargo build
```
then run the program

```bash
cargo run
```
if everything works, you'll get a notification based on the current called function in the main function

## Default Notification
![Image](/images/default_notification.JPG "Default Notification")

## Custom Message Notification
![Image](/images/custom_message_notirfication.JPG "Custom Message Notification"))

## Usage - Default Notification 

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MY_NOTIFICATION_ID 1
```

We import the necessary header files like:

* The windows header file `Windows.h` to interface with the windows api
* The string header file `string.h` for functions like **_snprintf_**

We'll use the [NOTIFYICONDATA](https://learn.microsoft.com/en-us/windows/win32/api/shellapi/ns-shellapi-notifyicondataa) struct that Contains information that the system needs to display notifications in the notification area. Used by Shell_NotifyIcon.

We declare this function that will be called from the rust generated executable
```c
__declspec(dllexport) void show_notification() {
    // Initialize the NOTIFYICONDATA structure
    NOTIFYICONDATA nid;
    //memset(&nid, 0, sizeof(NOTIFYICONDATA));
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow();
    nid.uID = MY_NOTIFICATION_ID;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1; // Custom message for notification events
    nid.hIcon = LoadIcon(NULL, IDI_INFORMATION); // Use a default information icon
    snprintf(nid.szTip, sizeof(nid.szTip), "%s", "My Notification");

    // Add the notification icon to the system tray
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Display a notification balloon
    nid.uFlags = NIF_INFO;
    nid.dwInfoFlags = NIIF_INFO;
    snprintf(nid.szInfo, sizeof(nid.szInfo), "%s", "Hello, this is a notification!");
    snprintf(nid.szInfoTitle, sizeof(nid.szInfoTitle), "%s", "Notification Title");
    Shell_NotifyIcon(NIM_MODIFY, &nid);

    // Wait for user input (for demonstration purposes)
    MessageBox(NULL, "Click OK to remove the notification.", "Notification Demo", MB_OK);

    // Remove the notification icon from the system tray
    Shell_NotifyIcon(NIM_DELETE, &nid);
}

```

On the rust side we'll use the [libc](https://crates.io/crates/libc) crate that provides all of the definitions necessary to easily interoperate with C code (or "C-like" code) on each of the platforms that Rust supports. 

```rust
#![allow(unused)]
extern crate libc;

// Specify the DLL name including the extension
#[link(name = "notification", kind = "raw-dylib")]
extern "C" {
    fn show_notification();
    fn show_notification_(message: *const libc::c_char);
}

fn main() {

    let message = "Hello from Rust!\0";

    unsafe {
        // Call the C function
        show_notification_(message.as_ptr() as *const libc::c_char);
    }
}

```

We use the `extern` keyword to define an external function interface in rust that allows us to call a c function from rust

The `unsafe` block is used because calling C functions ic considered unsafe in rust due to the lack of Rust safety guarantees in the C code.


```rust
#[link(name = "notification", kind = "raw-dylib")]
extern "C" {
    fn show_notification();
    fn show_notification_(message: *const libc::c_char);
}
```

We use the [link](https://doc.rust-lang.org/reference/items/external-blocks.html#the-link-attribute) attribute to link to the notification dll

We use [raw-dylib](https://doc.rust-lang.org/reference/items/external-blocks.html#dylib-versus-raw-dylib) because it's what's worked on windows system


## NOTE 

This project may be updated to use `extern "system"` [ABI](https://doc.rust-lang.org/reference/items/external-blocks.html#abi)


## Contributing

This project is a just a smple side project. Pull requests or suggestions are welcome. 

## License
[GNU](https://choosealicense.com/licenses/gpl-3.0/)