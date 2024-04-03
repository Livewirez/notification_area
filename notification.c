#include "notification.h"

/**
 * @brief Dynamic  Linked Library (DLL)
 * 
 *
 * @brief gcc -shared -o notification.dll notification.c
 * 
*/

/**
 * @brief Static Library
 * 
 *
 * @brief  gcc -c notification.c -o notification.o
 * @brief  ar rcs notification.lib notification.o
 * 
*/

/**
 * @brief Show hardcode messaged on windows notification bar
 * 
 * @return void 
 */
DLL_EXPORT extern void show_desktop_notification() {
    // Initialize the NOTIFYICONDATA structure
    NOTIFYICONDATA nid;
    //memset(&nid, 0, sizeof(NOTIFYICONDATA));
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow();
    nid.uID = MY_NOTIFICATION_ID;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1; // Custom message for notification events
    //nid.hIcon = LoadIcon(NULL, IDI_INFORMATION); // Use a default information icon
    nid.hIcon = LoadImage(NULL, IDI_INFORMATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE);
    _snprintf(nid.szTip, sizeof(nid.szTip), "%s", "My Notification");

    // Add the notification icon to the system tray
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Display a notification balloon
    nid.uFlags = NIF_INFO;
    nid.dwInfoFlags = NIIF_INFO;
    _snprintf(nid.szInfo, sizeof(nid.szInfo), "%s", "Hello, this is a notification!");
    _snprintf(nid.szInfoTitle, sizeof(nid.szInfoTitle), "%s", "Notification Title");
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
DLL_EXPORT extern void show_desktop_notification_(const char* message) {

    NOTIFYICONDATA nid;

    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow();
    nid.uID = MY_NOTIFICATION_ID;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1; // Custom message for notification events
    //nid.hIcon = LoadIcon(NULL, IDI_INFORMATION); // Use a default information icon
    nid.hIcon = LoadImage(NULL, IDI_INFORMATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE);
    _snprintf(nid.szTip, sizeof(nid.szTip), "%s", "Message");

    // Add the notification icon to the system tray
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Display a notification balloon
    nid.uFlags = NIF_INFO;
    nid.dwInfoFlags = NIIF_INFO;
    _snprintf(nid.szInfo, sizeof(nid.szInfo), "%s", message);
    _snprintf(nid.szInfoTitle, sizeof(nid.szInfoTitle), "%s", "Result");
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
DLL_EXPORT extern void show_desktop_notification_prog_name(const char* program_name, const char* message) {

    NOTIFYICONDATA nid;

    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow();
    nid.uID = MY_NOTIFICATION_ID;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_USER + 1; // Custom message for notification events
    //nid.hIcon = LoadIcon(NULL, IDI_INFORMATION); // Use a default information icon
    nid.hIcon = LoadImage(NULL, IDI_INFORMATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE);
    _snprintf(nid.szTip, sizeof(nid.szTip), "%s", "Message");

    // Add the notification icon to the system tray
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Display a notification balloon
    nid.uFlags = NIF_INFO;
    nid.dwInfoFlags = NIIF_INFO;
    _snprintf(nid.szInfo, sizeof(nid.szInfo), "%s", message);
    _snprintf(nid.szInfoTitle, sizeof(nid.szInfoTitle), "%s", program_name);
    Shell_NotifyIcon(NIM_MODIFY, &nid);

    // Wait for user input (for demonstration purposes)
    //MessageBox(NULL, "Click OK to remove the notification.", "Notification Demo", MB_OK);

    // Remove the notification icon from the system tray
   // Shell_NotifyIcon(NIM_DELETE, &nid);
}