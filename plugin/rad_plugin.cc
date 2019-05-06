#ifndef _RAD_PLUGIN_HH_
#define _RAD_PLUGIN_HH_

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
#include "kh_02.hpp"

using namespace std;

class radPlugin;


namespace gazebo {

    class radPlugin : public ModelPlugin{
    public:
        radPlugin(){}



        virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf){
            con_T(__func__);
            assignMembers(_model);
            pidToJoints();

            this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                std::bind(&radPlugin::OnUpdate, this));


        }



        void OnUpdate(){
            this->SetVelocity(5);
        }



        //////////////////////////////////////////////////////////////////////

        void assignMembers(physics::ModelPtr _model){

            con_T(__func__);
            this->model   = _model;
            this->wheelJ1 = model->GetJoints()[3];
            this->wheelJ2 = model->GetJoints()[4];

            con_T("name of model : " + model  ->GetName() );
            con_T("name of j1    : " + wheelJ1->GetName() );
            con_T("name of j2    : " + wheelJ2->GetName() );

        }


        void pidToJoints(){

            con_T(__func__);

            this->pid1 = common::PID(0.1, 0, 0);
            this->pid2 = common::PID(0.1, 0, 0);

            this->model->GetJointController()->SetVelocityPID(
                this->wheelJ1->GetScopedName(), this->pid1);
            this->model->GetJointController()->SetVelocityPID(
                this->wheelJ2->GetScopedName(), this->pid2);

        }

        void SetVelocity(int _vel){

            this->model->GetJointController()->SetVelocityTarget(
                this->wheelJ1->GetScopedName(), -_vel);

            this->model->GetJointController()->SetVelocityTarget(
                this->wheelJ2->GetScopedName(), _vel);

        }




    private:
        event::ConnectionPtr updateConnection;
        physics::ModelPtr model;
        physics::JointPtr wheelJ1;
        physics::JointPtr wheelJ2;
        common::PID pid1;
        common::PID pid2;
     };

    GZ_REGISTER_MODEL_PLUGIN(radPlugin)

}









#endif
