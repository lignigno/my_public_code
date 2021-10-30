# A little code for convenient generation of a sequence of colors<br>

### launch
bash-3.2$ make <br>
bash-3.2$ Press "COMMAND + V" <br>

<br>

code for ***stm32 + ws2812b***

### usage example <br>
(the sweetest thing at the end)

<br><hr><br>
![code_example_0](/plyhi/for_LEDs/img_for_git/code_0.png) ![res_example_0](/plyhi/for_LEDs/img_for_git/res_0.png)
<br><hr><br>
![code_example_1](/plyhi/for_LEDs/img_for_git/code_1.png) ![res_example_1](/plyhi/for_LEDs/img_for_git/res_1.png)
<br><hr><br>
![code_example_2](/plyhi/for_LEDs/img_for_git/code_2.png) ![res_example_2](/plyhi/for_LEDs/img_for_git/res_2.png)
<br><hr><br>
![code_example_3](/plyhi/for_LEDs/img_for_git/code_3.png) ![res_example_3](/plyhi/for_LEDs/img_for_git/res_3.png)
<br><hr><br>
![code_example_4](/plyhi/for_LEDs/img_for_git/code_4.png) ![res_example_4](/plyhi/for_LEDs/img_for_git/res_4.png)
<br><hr><br>
![code_example_5](/plyhi/for_LEDs/img_for_git/code_5.png) ![res_example_5](/plyhi/for_LEDs/img_for_git/res_5.png)
<br><hr><br>

> In this example, I use "LightUpSingleLEDIter" instead of "LightUpLEDsRangeIter".
> This is because the "LightUpLEDsRangeIter" after generating a sequence of bits
> for few LEDs sets another bit to 0 to avoid garbage when generating PWM in CIRC mode.
> And this bit changes the color of the next LED.<br>
> As example :<br>
> FALSE = 13;<br>
> TRUE = 26;<br>
> RESET = 0;<br>
> LED_0 = |13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13| "BLACK"<br>
> LED_1 = |13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13| "BLACK"<br>
> LED_2 = |26|26|26|26|26|26|26|26|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13| "RED"<br>
> LightUpLEDsRangeIter(arr, 1, 2, color /* 0x0000FF */);<br>
> LED_0 = |13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|<br>
> LED_1 = |13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|26|26|26|26|26|26|26|26|<br>
> LED_2 = |0|26|26|26|26|26|26|26|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|13|

![code_example_6](/plyhi/for_LEDs/img_for_git/code_6.png) ![res_example_6](/plyhi/for_LEDs/img_for_git/res_6.png)
<br><hr><br>

> An example of what can be done with an LED strip using these functions.<br>
> (yes, you can assemble a lightmusic or an equalizer)

![res_example_7](/plyhi/for_LEDs/img_for_git/volume.gif)
<br><hr><br>
