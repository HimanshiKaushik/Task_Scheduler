#include<iostream>
#include<queue>
#include<string>
#include<functional>

using namespace std;

struct Task{
    string name;
    int priority;
};

struct CompareTask{
    bool operator()(Task const& t1,Task const& t2){
        return t1.priority>t2.priority;
    }
};

class TaskScheduler{
    private:
    priority_queue<Task, vector<Task>, CompareTask> pq;
    public:
    void addTask(const string& name, int priority){
        pq.push(Task{name,priority});
    }

    Task getNextTask(){
        if(pq.empty()){
            throw runtime_error("No tasks available");
        }
        Task nextTask=pq.top();
        pq.pop();
        return nextTask;
    }
    bool isEmpty() const{
        return pq.empty();
    }
};

int main(){
    TaskScheduler scheduler;
    scheduler.addTask("Task1",2);
    scheduler.addTask("Task2",1);
    scheduler.addTask("Task3",3);

    while(!scheduler.isEmpty()){
        Task nextTask=scheduler.getNextTask();
        cout<<"Next Task:"<<nextTask.name<<" with priority "<<nextTask.priority<<endl;
    }

    return 0;
}