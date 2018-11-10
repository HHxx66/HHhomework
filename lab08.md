# Top-down 编程法

## 介绍

Top-down本质是系统的破坏，以逆向工程的方式深入了解其组成子系统。在分解的过程中，系统将逐步细化，直至分解为基本元素。

![](//upload.wikimedia.org/wikipedia/commons/thumb/4/4f/Lego_Chicago_City_View_2001.jpg/220px-Lego_Chicago_City_View_2001.jpg)

Top-down编程法是传统程序语言的主流，其从指定复杂的部分开始，将它们分成连续的小部分，然后再把每一小部分解决，最终得以解决问题。这样一来，任何复杂的问题都可以通过解决一个个小问题来解决，这样一来，复杂问题就简单化了，所以说，Top-down的编程法也不失为一种解决复杂问题的好方法。

## 案例

洗衣机的正常洗衣过程

![](http://img2.zol.com.cn/product/84/349/ceRIdLsjCKM8k.jpg)

```
READ 洗衣模式 && 水位

water_in_switch(open)
IF get_water_volume() equal to 设置的水位 THEN
	water_in_swicth(close)
ENDIF

IF time_counter() equal to 洗衣机内部设定的浸泡时间 THEN
	WHILE time_counter() <= 洗衣机内部设定的洗涤时间
		WHILE time_counter() <= 电机左转时间
			motor_run(left)
		ENDWHILE
		WHILE time_counter() <= 电机左转时间
			motor_run(right)
		ENDWHILE
	ENDWHILE
ENDIF

water_out_switch(open)
IF get_water_volume() equal to 0 THEN
	water_out_switch(close)
ENDIF

water_in_switch(open)
IF get_water_volume() equal to 设置的水位 THEN
	water_in_swicth(close)
ENDIF

WHILE time_counter() <= 洗衣机内部设定的漂洗时间
	WHILE time_counter() <= 电机左转时间
		motor_run(left)
	ENDWHILE
	WHILE time_counter() <= 电机左转时间
		motor_run(right)
	ENDWHILE
ENDWHILE

water_out_switch(open)
IF get_water_volume() equal to 0 THEN
	water_out_switch(close)
ENDIF

WHILE time_counter() <= 洗衣机内部设定的脱水时间
	motor_run(left)
ENDWHILE

halt(success)
```

这是大致的过程，其实真正的比这还要复杂。不过没关系，用Top-down的方法将其分解为一个个小问题就可以慢慢解决。

（1）模式选择：这一步问题不大。

READ 洗衣模式 && 水位

（2）注水：注水是按照预先设定的水位和水位计的水位来的。

water_in_switch(open)
IF get_water_volume() equal to 设置的水位 THEN
	water_in_swicth(close)
ENDIF

（3）浸泡跟洗涤是紧接着的，所以我们可以一同解决。同样都需要计时器计时。

IF time_counter() equal to 洗衣机内部设定的浸泡时间 THEN
	WHILE time_counter() <= 洗衣机内部设定的洗涤时间
		WHILE time_counter() <= 电机左转时间
			motor_run(left)
		ENDWHILE
		WHILE time_counter() <= 电机左转时间
			motor_run(right)
		ENDWHILE
	ENDWHILE
ENDIF

（4）排水跟注水大同小异。

water_out_switch(open)
IF get_water_volume() equal to 0 THEN
	water_out_switch(close)
ENDIF

（5）漂洗跟洗涤也差别不大。

WHILE time_counter() <= 洗衣机内部设定的漂洗时间
	WHILE time_counter() <= 电机左转时间
		motor_run(left)
	ENDWHILE
	WHILE time_counter() <= 电机左转时间
		motor_run(right)
	ENDWHILE
ENDWHILE

（6）脱水：脱水需要电机与计时器。

WHILE time_counter() <= 洗衣机内部设定的脱水时间
	motor_run(left)
ENDWHILE

（7）最后洗衣完成。

halt(success)

把上述的一个个小问题的伪代码适当拼接，就可以拼成完整的正常洗衣过程伪代码了。所以说，运用Top-down的方法，再复杂的问题也能解决，只不过是时间问题罢了。