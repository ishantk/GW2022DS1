#include<iostream>
using namespace std;

// Youtube Channel can be subcribed by a User.
// When a new Video is uploaded a notification must be sent to the User

// In C++ a class containing only pure virtual functions is referred to as Interface
class Notificaton{
    public:
        virtual void notify(string message)=0;
};

class User: public Notificaton{ // Implementing Notification Interface

    string name;
    string email;

    public:
    User(): name("John"), email("john@gmail.com"){

    }

    void notify(string message){
        cout<<"Dear, "<<name<<" A new Notification Arrived"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<message<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
};

class YoutubeChannel{

    string channelName;
    Notificaton *ptr; // Its a Pointer to Notification

    public:

    YoutubeChannel(): channelName("Auribises"), ptr(NULL) {

    }

    // subscribe function takes reference to User Object as Input
    void subcribe(User &user){
        // Notification points to address of User Object
        ptr = &user;
    }

    void unsubcribe(){
        ptr = NULL;
    }
    
    void uploadVideo(string title){
        cout<<"[YoutubeChannel > uploadVideo] A new Video Uploaded on "<<channelName<<endl;
        cout<<"[YoutubeChannel > uploadVideo] Video Title: "<<title<<endl;

        if(ptr != NULL)
            ptr->notify("A new Video Uploaded");
    }

};

int main(){

    User john;

    YoutubeChannel channel;
    channel.subcribe(john);
    //channel.unsubcribe();

    channel.uploadVideo("C++ Is Awesome.mp4");

    return 0;
}
