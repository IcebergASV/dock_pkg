# Commands to run

- roslaunch boat_sim boat.launch
- rosrun rviz rviz
- Insert dock
- Add a LaserScan visualization in rviz, and attach to topic `laser/scan`
- You may have to change fixed frame (in global options on left side) in rviz from `map` to `hokuyo_sensor_link` to enable lidar in rviz.
- Experiement as needed


# Assumptions

- Assume we know which dock to go (1, 2, 3)


# Plan of attack

- [ ] Visualize the situation in simulation
- [ ] Determine what topics you need to subscribe to
- [ ] Get numerical lidar data, and then see what you can do
