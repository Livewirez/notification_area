// main.rs
#![allow(unused)]
extern crate libc;

#[link(name = "notification", kind = "raw-dylib")]
extern "C" {
    fn show_desktop_notification();
    fn show_desktop_notification_(message: *const libc::c_char);
    fn show_desktop_notification_prog_name(program_name: *const libc::c_char, message: *const libc::c_char);
}

fn main() {

    let message = "Hello from Rust!\0";

    unsafe {

        // show_desktop_notification_(message.as_ptr() as *const libc::c_char);

        show_desktop_notification_prog_name("Anime!\0".as_ptr() as *const libc::c_char, "Mode: Saitama\0".as_ptr() as *const libc::c_char);

    }
}