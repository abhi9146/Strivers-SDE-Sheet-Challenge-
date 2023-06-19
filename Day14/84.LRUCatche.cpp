
#include<bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    int cap;
    int minFreq;
    unordered_map<int,pair<int,int>>keyVal;
    unordered_map<int,list<int>>freqList;
    unordered_map<int,list<int>::iterator>pos;

    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
    }
    
    int get(int key) {
        if(keyVal.find(key)==keyVal.end()){
          return -1;
        }
        
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();

        if(freqList[minFreq].empty()) minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        
        if(keyVal.find(key)!=keyVal.end()){
           keyVal[key].first=value;
           freqList[keyVal[key].second].erase(pos[key]);
           keyVal[key].second++;
           freqList[keyVal[key].second].push_back(key);
           pos[key] = --freqList[keyVal[key].second].end();

           if(freqList[minFreq].empty()) minFreq++;
           return ;
        }
        if(keyVal.size() == cap) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */