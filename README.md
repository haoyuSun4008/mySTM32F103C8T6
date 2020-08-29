# mySTM32F103C8T6
study cm3

# Debug Experience
1. add CAN   HardFault
2. add WatchDog Timer
3. Timer4 HardFault
4. Reg Code can be replaced by Lib Code
5. CanMsg not received in CanPro still.

# 多次出现硬件故障中断的原因发现一层
1. 配置结构体初始化为指针变量后，对结构体指针的成员进行引用赋值时会进入硬件故障中断；
2. 现已采用非指针化的配置结构体初始化方式进行变量初始化，无硬件故障中断出现；
3. 深层原因尚未探寻；

# 提交代码到分支1
1. git add .
2. git commit -m "comment"
3. git push -u origin dev1

# 不提交当前已修改的分支2但切换到分支1
1. git stash
2. git checkout dev1

# 提交修改的分支1后切入分支2继续已暂存的修改
1. git checkout dev2
2. git stash pop