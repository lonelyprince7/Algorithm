#include<bits/stdc++.h>
#include<vector>
using namespace std;
class LFUCache{
    map<int,int> data; //每一个key对应一个value
    map<int,int> time; //安一个定时器,不取一直涨,一取到就清零
    map<int,int> count; //某项所有操作次数
    int capacity;
    int size;
public:
    LFUCache(int capacity){
        this->capacity=capacity;
        this->size=0;
    }
    int get(int key){
        int tmp=data[key];
        count[key]++;
        //除key外的所有key+1;
        for(auto i:data)
        {
            if(i.first==key) time[i.first]=0;
            else time[i.first]++;
        }
        if(tmp)return tmp;
        else return -1;
    }
    void put(int key,int value){
        if(data[key]){
            data[key]=value;
            count[key]++;
        }
        else{
            ++size;
            if(size>capacity){
                --size;
                vector<int> min_keys;
                min_keys.push_back((count.begin())->first);
                vector<int> min_counts;
                min_counts.push_back(count.end()->second);
                for(auto i:data){
                    if(count[i.first]<min_counts[0]){
                        min_keys.clear();
                        min_counts.clear();
                        min_keys.push_back(i.first);
                        min_counts.push_back(count[i.first]);  
                    }
                    else if(count[i.first]==min_counts[0]){
                        min_keys.push_back(i.first);
                    }
                }
                int max_key=min_keys[0];;
                for(int i:min_keys){
                    if(time[i]>time[max_key]) max_key=i;
                }
                cout<<"max_key"<<max_key<<endl;
                data.erase(max_key);
                data[key]=value;
                count[key]++;
                count[max_key]=0;
            }
            else{
                data[key]=value;
            }
        }
        for(auto i:data)
        {
            if(i.first==key) time[i.first]=0;
            else time[i.first]++;
        }
    }

};
int main(){
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // 返回 1
    cache.put(3, 3);    // 去除 key 2
    cout<<cache.get(2)<<endl;       // 返回 -1 (未找到key 2)
    cout<<cache.get(3)<<endl;       // 返回 3
    cache.put(4, 4);    // 去除 key 1
    cout<<cache.get(1)<<endl;       // 返回 -1 (未找到 key 1)
    cout<<cache.get(3)<<endl;       // 返回 3
    cout<<cache.get(4)<<endl;       // 返回 4
    return 0;
}