#include<iostream>
using namespace std;

class Review{

    public:
        string userName;
        string text;
        int likes;
        int dislikes;

        Review* nextReview;
        Review* previousReview;

        Review(): userName(""), text(""), likes(0), dislikes(0), nextReview(NULL), previousReview(NULL){

        }

        Review(string userName, string text, int likes, int dislikes): userName(userName), text(text), likes(likes), dislikes(dislikes), nextReview(NULL), previousReview(NULL){

        }

        void show(){
            cout<<"____________________________________"<<endl;
            cout<<userName<<endl;
            cout<<text<<endl;
            cout<<"Likes: "<<likes<<" DisLikes: "<<dislikes<<endl;
            cout<<"____________________________________"<<endl;
        }
};


class ReviewDoublyLinkedList{

    public:
    
    Review* head; // head will point to the first object in the ReviewDoublyLinkedList
    Review* tail; // tail will point to the last object in the ReviewDoublyLinkedList

    int size;

    ReviewDoublyLinkedList(): head(NULL), tail(NULL), size(0){
        cout<<"[ReviewDoublyLinkedList] Created"<<endl;
        cout<<"[ReviewDoublyLinkedList] head: "<<head<<" tail: "<<tail<<" size: "<<size<<endl;
    }

    void add(Review* review){

        size++;

        cout<<"[ReviewDoublyLinkedList] [add] review is: "<<review<<" size: "<<size<<endl;

        if(head == NULL){
            head = review;
            tail = review;
            cout<<"[ReviewDoublyLinkedList] [add] [if] head: "<<head<<" tail: "<<tail<<" size: "<<size<<endl;
        }else{
            tail->nextReview = review;
            review->previousReview = tail;
            tail = review;
            cout<<"[ReviewDoublyLinkedList] [add] [else] head: "<<head<<" tail: "<<tail<<" size: "<<size<<endl;
        }

        cout<<"[ReviewDoublyLinkedList] [add] review's "<<review<<" next review is: "<<review->nextReview<<" previous review is: "<<review->previousReview<<endl;

    }

    void iterateForward(){

        Review* temp = head;
        while(true){

            temp->show();
            temp = temp->nextReview;

            if(temp == NULL){
                break;
            }

        }
    }

    void iterateBackward(){

        Review* temp = tail;
        while(true){

            temp->show();
            temp = temp->previousReview;

            if(temp == head){
                break;
            }

        }
        temp->show();
    }

};

int main(){
    

    ReviewDoublyLinkedList* reviewList = new ReviewDoublyLinkedList();

    Review* review1 = new Review("al san", "Great great work by ishant..", 0, 0);
    Review* review2 = new Review("aish gk", "Thank you so much, edureka! for uploading this video. ", 13, 0);
    Review* review3 = new Review("Mokshada Nayak", "Very informative video and nicely explained.Very well done.Thank you so much for sharing with us.", 16, 3);

    reviewList->add(review1);
    reviewList->add(review2);
    reviewList->add(review3);

    //reviewList->iterateForward();
    reviewList->iterateBackward();

    return 0;
}
