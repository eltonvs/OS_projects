---
layout: post
title: "Fairy Lights on BeagleBone Black"
description: "Project Description Here"
date: 2016-09-23
tags: [beaglebone, electronics, gpio]
comments: true
share: true
---


### Project Requirements
 - 1 RGB Led
 - 1 Red Led
 - 1 220Ω Resistor
 - 1 1000Ω Resistor
 - 3 100Ω Resistor
 - 1 Button
 - 1 Photosensor
 - 1 Potentiometer
 - 1 BeagleBone Black

---

### How to Make

<div class="full-width-video">
  <iframe width="1280" height="720" src="https://www.youtube.com/embed/ptromyXpk8c?rel=0" frameborder="0" allowfullscreen></iframe>
</div>

---

### Code

All sources to execute this project are available on [GitHub](https://github.com/eltonvs/beagleproject/tree/master/FairyLights).

---

### Run on BeagleBone Black

To run this project you just need to copy the binary file (generated on `bin` folder) to your BeagleBone Black Board (you can use `ssh` to do this).

Run this on your machine:

```
$ scp bin/fairylights debian@192.168.7.2:~/
```

 > The user (`debian`) and the IP address (`192.168.7.2`) may be different according with your system.

After that, you should to enter on beagle (using ssh again) and became root. So, after you're inside BeagleBone, navigate to folder that you copied the binary file and run this on terminal:

```
$ sudo su        # To became root
$ ./fairylights  # Execute the binary file
```
