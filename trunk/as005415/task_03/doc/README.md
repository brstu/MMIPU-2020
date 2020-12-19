# Laboratory work #3
### Student: Shestakov Mark
##### Task 3. In Eclipse environment create test project hello world, build it and launch it on test controller AXC F 2151

What i do step by step:
1. Install Ubuntu 20.04 on Virtual Machine (VirtualBox)
2. Follow task_03 instructions for bulding "Hello World" app
3. Configure VM:
    - Enable Network Adapter
    - Attached to: Bridged Adapter
    - Name: Name of LAN adapter
4. Connect my laptop to controller with ethernet cable
5. configured network adapter
    - IPv4:192.168.1.11
    - NetMask:255.255.255.0
6. Checked connection: ```ping 192.168.1.10```
7. Connect to controller in file manager to copy my program to it
8. Connect to controller via terminal: ```ssh admin@192.168.1.10```
9. Execute program via terminal


#### Code:
```c++
//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Hello Mark" << endl;
	return 0;
}
```

#### Result:
[![Watch the video](https://img.youtube.com/vi/kTgPRPUCaZw/0.jpg)](https://youtu.be/kTgPRPUCaZw)