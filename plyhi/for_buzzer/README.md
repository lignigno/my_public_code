# Some functions for working with buzzers<br>

### buzzer.h<hr>
You need to connect the project header file to "buzzer.h"<br>

![connecting a project to buzzer.h](/plyhi/for_buzzer/img_for_git/inc_in_buzzer_h.png)<br><br>

Set the initial volume for each type of sound<br>

![initials_start_volumes](/plyhi/for_buzzer/img_for_git/initials_volumes.png)<br><br>

For proper operation, set the appropriate values
- TIM_FRQ - the frequency at which the bus operates with the necessary timer
- PERIOD_SIG - the number of parts that make up single signals

(full explanation will be later)<br>

![timer_frequencies](/plyhi/for_buzzer/img_for_git/setting_timer_frequencies.png)<br>

Necessary registers for timer control<br>

![timer_registers](/plyhi/for_buzzer/img_for_git/timer_registers.png)<br>

Set the appropriate types for your environment<br>

![users_types](/plyhi/for_buzzer/img_for_git/set_sys_types.png)<br>

<br>
<br>

### users_wrapers.c<hr>

add the necessary variables to work with the extern keyword<br>

![extern_vars](/plyhi/for_buzzer/img_for_git/extern_vars.png)<br>

If you use dma, then you need to write instructions for installing dma in circ mode<br>

![installing circ for dma](/plyhi/for_buzzer/img_for_git/set_circ.png)<br>

Here you need to write down how you will generate pwm.<br>
If you use something other than dma and try to use MODE_SIN or MODE_SQL,<br>
a PWM signal with a Pulse frequency will be generated<br>

![starting pwm generation](/plyhi/for_buzzer/img_for_git/pwm_start.png)<br>

How will you stop generating pwm<br>

![stopping pwm generation](/plyhi/for_buzzer/img_for_git/pwm_stop.png)<br>

Process delay during music<br>

![duration_func](/plyhi/for_buzzer/img_for_git/duration.png)<br>

<br>
<br>

### Usage example<hr>

Function with recorded music<br>

	/* USER CODE BEGIN 0 */

	#define SIZE_ARR(arr) (sizeof(arr) / sizeof(arr[0]))

	void	music_1(u8_t mode)
	{
		double		notes[] = {C, C_, D, D_, E, F ,F_ ,G , G_, A, A_, B};
		u8_t		arrNote[] = {7, 5, 7, 5, 7, 0, 0,
								7, 5, 7, 5, 7, 0, 0,
								3, 5, 3, 5, 3, 7, 7,
								3, 5, 5, 5, 3, 7, 7,
								7, 5, 7, 5, 7, 0, 0,
								7, 5, 7, 5, 7, 0, 0,
								3, 5, 3, 5, 3, 7, 7,
								3, 5, 5, 5, 3};

		u64_t		num = SIZE_ARR(arrNote);

		uint16_t	arrDuration[] = {200,200,200,200,200,300,300,
									200,200,200,200,200,300,300,
									200,200,200,200,200,300,300,
									200,200,200,200,200,300,300,
									200,200,200,200,200,300,300,
									200,200,200,200,200,300,300,
									200,200,200,200,200,300,300,
									200,200,200,200,200};

		if (num != SIZE_ARR(arrDuration))
			return ;

		for (size_t i = 0; i < num; i++)
		{
			PlaySoundRawFrq(notes[arrNote[i]] * (1 << 5), arrDuration[i], mode);
			HAL_Delay(20);
		}
	}

	/* USER CODE END 0 */

Example with three different types of signals<br>

	/* USER CODE BEGIN 2 */

	InitSound();

	music_1(MODE_SIN);
	HAL_Delay(1000);

	PlaySound(FRQ(6, 5), 300, MODE_SQR);
	HAL_Delay(500);

	music_1(MODE_SQR);
	HAL_Delay(1000);

	PlaySound(FRQ(6, 5), 300, MODE_SQR);
	HAL_Delay(500);

	music_1(MODE_PWM);

	/* USER CODE END 2 */

Other examples will come later

<br>
<br>

### Еhe experience gained<hr>

Idea =)<br>

![code](/plyhi/for_buzzer/img_for_git/code_for_cool_res.png)<br>

![result](/plyhi/for_buzzer/img_for_git/cool_res.png)<br>

Why was it reJected =(<br>

Everything is fine, but a lot of calculations<br>
that greatly slow down the execution, and requires a lot of memory.<br>

And the rest that I will describe, but later
