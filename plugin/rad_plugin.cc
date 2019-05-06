#ifndef _RAD_PLUGIN_HH_
#define _RAD_PLUGIN_HH_

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
#include "/home/hyeok/KH/KH_01/KH_02.hpp"


using namespace std;

namespace gazebo {

    class radPlugin : public ModelPlugin{
    public:
        radPlugin(){}
        virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf){

            cout << "cout from Load" << endl;
            con_T(__func__);
            int sus[10] = {10, 10, 0};

        }


    private:
        physics::ModelPtr model;
        physics::JointPtr wheelJ1;
        physics::JointPtr wheelJ2;
        common::PID pid;
    };

}









#endif
