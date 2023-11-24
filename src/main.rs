// main.rs
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