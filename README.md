# Gym-app
Records scores and personal bests from gym classes.

I wrote this app as C++ practice, it is meant as a first step towards a larger app that would automate the collection of data from a gym class to provide personalised statistics and training goals. 

The app lets the user specify "routines" and input user scores for sessions of that routine. A routine consists of a list of users,a list of sessions and a list of exercises for which each user is scored each session. As new sessions are inputted the app keeps track of each users personal bests for each exercise and also calculates each users score as a percentage of either their previous personal best or a fixed reference score depending on the exercise. The personal bests, exercises, raw scores and calculated scores are saved to file as shown in the file structure below.



![Alt text](demo.gif?raw=true "app Demo")
![Alt text](file_system.png?raw=true "app file system Demo")
