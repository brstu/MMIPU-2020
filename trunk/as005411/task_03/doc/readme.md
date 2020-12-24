# Laboratory work 3

## Performed by Rakhlei Vitali

### Task: Hello World on **AXC F 2152** controller.

### Additional instructions of environment setup:

[**How To install Linux (Ubuntu) tools for C++ programming with Eclipse IDE**](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20install%20Linux%20(Ubuntu)%20tools%20for%20C%2B%2B%20programming%20with%20Eclipse%20IDE)

## Code:

```c++
//============================================================================
// Name        : l3c.cpp
// Author      : Vitali Rakhlei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
```

## Video:

[![Watch the video](https://img.youtube.com/vi/sxThWMHmULM/0.jpg)](https://youtu.be/sxThWMHmULM)



## Step by step work app execution.

1. Connect controller and laptop with RJ45 networking cord.
2. Set up connection settings in "Network" tab.
3. Ping controller from console with ```ping 192.168.1.10```.
4. Connect to controller's file server from File Explorer with ```ssh://192.168.1.10```.
5. Copy built Hello World app to controller's file system.
6. Connect to controller server from terminal with ```ssh 192.168.1.10```.
7. Find Hello World app in terminal and execute it with ```./l3c```.
8. Enjoy.