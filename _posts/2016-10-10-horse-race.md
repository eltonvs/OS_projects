---
layout: post
title: "Horse Race on BeagleBone Black"
description: "Project Description Here³"
date: 2016-10-10
tags: [beaglebone, electronics, gpio, game]
comments: true
share: true
---

### Project Requirements
 - 1x RGB Led
 - 1x Red Led
 - 1x 220Ω Resistor
 - 1x 1000Ω Resistor
 - 3x 100Ω Resistor
 - 1x Button
 - 1x Potentiometer
 - 1x BeagleBone Black

---

### How to Make

<div class="full-width-video">
  <iframe width="1280" height="720" src="https://www.youtube.com/embed/aNqMWlZi-1U?rel=0" frameborder="0" allowfullscreen></iframe>
</div>

---

If you don't wanna watch the video, there's a sketch:

![BeagleBone Sketch]({{ site.baseurl }}/assets/images/posts/beaglebone_fairylights_sketch.png)

---

### Code

All sources to execute this project are available on [GitHub](https://github.com/eltonvs/beagleproject/tree/master/HorseRace).

---

### Run on BeagleBone Black

To run this project you just need to copy the binary file (generated on `bin` folder) to your BeagleBone Black Board (you can use `ssh` to do this).

Run this on your machine:

```
$ scp bin/horserace debian@192.168.7.2:~/
```

 > The user (`debian`) and the IP address (`192.168.7.2`) may be different according with your system.

After that, you should to enter on beagle (using ssh again) and became root. So, after you're inside BeagleBone, navigate to folder that you copied the binary file and run this on terminal:

```
$ sudo su        # To became root
$ ./horserace  # Execute the binary file
```

---

### Understanding the game...

Before to start the racing, it is necessary to define the quantity of horses, for it we will need to use the Potentiometer, we had define on code that the maximum  and minimum number of horses (2 & 4, respectively). The user will know the number of horses by the RGB led, whether the led is blue, it means that we have 2 horses, whether the led is green, it means that we have 3 horses, and whether the led is red, we will have 4 horses.

After we select the number of horses, it’s time to start the game, so we press the button (the red led will signalize that the Racing has begun). When the Racing is over, the color of the winner will appear on the RGB led.

- Horse 1 - Blue
- Horse 2 - Green
- Horse 3 - Red
- Horse 4 - White

When we press the button to start the Racing, the application will read the quantity of horses that was declared on the potentiometer and will create a process for each horse on the Racing by using `fork()` command. Each process represents  a horse. Each process will generate random numbers (Always positive, to avoid that the horse goes on the wrong direction) and will add these numbers on their respective process during 5 seconds, after 5 seconds the BeagleBone will check in a log file what process will has the greater result and will turn on the winner’s light on the RGB led.
