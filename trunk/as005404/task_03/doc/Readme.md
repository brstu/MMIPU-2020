# Laboratory work #3

### Student: Isachenka Anton
##### Task 3. In Eclipse environment create test project hello world, build it and launch it on test controller AXC F 2151

During the work with controller I faced several problems:

1. Firstly we though that we need launch our program with help of eclipse, installing add-in but this didn't work.
2. Then we discovered that we need to connect to controller like other linux machine and launch program on it but we had some problems with this, because we couldn't do this no matter how we change network settings.
3. But then someone suggested that we need to put in ethernet cable in other RJ45 port because this port is for modules connecting and all worked.
4. I personally with my laptop encounter other problem, terminal throw an error that port 22 is refused my connection, to repair this I needed to reload controller, this problem was because someone before me forgot to properly exit(command 'exit') from controller.

##### Code:

```c++
// Name        : helloworld.cpp
// Author      : Isachnkak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Hello World!!!" << endl;
	return 0;
}```
```

Video with my results:

[![Watch the video](https://img.youtube.com/vi/RQdaUR5X0fo/maxresdefault.jpg)](https://youtu.be/RQdaUR5X0fo)