#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MY_NOTIFICATION_ID 1

/**
 * @brief gcc -shared -o notification.dll notification.c
 * 
 */


/**
 * @brief Show hardcode messaged on windows notification bar
 * 
 * @return void 
 */
__declspec(dllexport) void show_notification() {
    // Initialize the NOTIFYICONDATA structure
    NOTIFYICONDATA nid;
    //memset(&nid, 0, sizeof(NOTIFYICONDATA));
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow();
    nid.uID = MY_NOTIFICATION_ID;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1; // Custom message for notification events
    nid.hIcon = (HICON)LoadImage(NULL, "C:\\Users\\hp\\Downloads\\twitter2x.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE); // Use a default information icon
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

/**
 * @brief Show message passed in on windows notification bar
 * 
 * @return void 
 */
__declspec(dllexport) void show_notification_(const char* message) {

    NOTIFYICONDATA nid;

    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow();
    nid.uID = MY_NOTIFICATION_ID;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1; // Custom message for notification events
    nid.hIcon = (HICON)LoadImage(NULL, "C:\\Users\\hp\\Downloads\\twitter2x.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);  // Use a default information icon
    snprintf(nid.szTip, sizeof(nid.szTip), "%s", "Message");

    // Add the notification icon to the system tray
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Display a notification balloon
    nid.uFlags = NIF_INFO;
    nid.dwInfoFlags = NIIF_INFO;
    snprintf(nid.szInfo, sizeof(nid.szInfo), "%s", message);
    snprintf(nid.szInfoTitle, sizeof(nid.szInfoTitle), "%s", "Result");
    Shell_NotifyIcon(NIM_MODIFY, &nid);

    // Wait for user input (for demonstration purposes)
    MessageBox(NULL, "Click OK to remove the notification.", "Notification Demo", MB_OK);

    // Remove the notification icon from the system tray
    Shell_NotifyIcon(NIM_DELETE, &nid);
}