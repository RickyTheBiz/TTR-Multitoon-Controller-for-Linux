# TTR-Multitoon-Controller-for-Linux
This program has been tested on Ubuntu 14.04.  It will likely run on other flavors of linux but dependency packages names may differ.  This is a very rudimentary program so feel free to improve upon it.

#####How to use it:
1. Open two instances of Toontown Rewritten and load your toons.
2. There are two buttons available on the GUI.  Click on one of them to set the window to correspond to that controls.
3. Within 3 seconds click the TTR window you wish to bind to those keys.
4. Wait until your toon jumps or wait for more than 3 seconds.
5. Click the other button and repeat for the 2nd window.
6. Once both windows are bound, you can control each toon independently whenever the controller window is clicked on.
7. To chat, pick gags, or otherwise temporarily disable the controls simply click on one of the TTR windows.
8. To re-enable the controls click on the controls window
9. If a toon crashes, simply click the button again, then the window, and your toon will be bound to those controls again.

#####Controls
WASD Toon:  
W = Forward  
A = Left  
S = Backward  
D = Right  
Shift = Jump  
E = Throw pie or evidence  

Arrows Toon:  
Arrow Key Up = Forward  
Arrow Key Left = Left  
Arrow Key Right = Right  
Arrow Key Down = Down  
Control = Jump  
Delete = Throw pie or evidence  

Both Toons:  
Home = Brings up gag preview on both toons  
End = Brings up toontask preview on both toons  

#####Advanced
To create a hotkey to activate the controls, a script is included called activate.sh.  To use it simply use your favorite hotkey program and setup a hotkey to run it.  This will let you activate the controls without manually clicking on the controls window.

#####Dependencies
xdotool
Qt5
git

#####How to compile
Under Ubuntu:  
`sudo apt-get install xdotool git qt-sdk build-essential`  
`git clone https://github.com/RickyTheBiz/TTR-Multitoon-Controller-for-Linux.git`  
`cd TTR-Multitoon-Controller-for-Linux`  
`qmake`  
`make`  
