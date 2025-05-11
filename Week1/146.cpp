#include <unordered_map>    // 引入 unordered_map，用於快速查找 key 是否存在
#include <list>             // 引入 list，用於維護快取資料的使用順序

// 定義 LRUCache 類別
class LRUCache {
public:
    // 建構子：初始化 LRU 快取，設定最大容量
    LRUCache(int capacity) {
        this->capacity = capacity;  // 設定快取容量
    }
    
    // get 函數：取得 key 對應的值，如果 key 不存在則返回 -1
    int get(int key) {
        // 檢查哈希表中是否存在該 key
        if (map.find(key) == map.end())
            return -1; // 若 key 不存在，返回 -1

        // 若存在，取得該 key 在 list 中的迭代器
        auto it = map[key];
        int value = it->second;  // 取得對應的 value

        // 為了表示該元素最近被使用，先將其從快取中移除
        cache.erase(it);
        // 再將該 key-value 對插入到 list 的前端（代表最新使用）
        cache.push_front({key, value});
        // 更新哈希表中該 key 對應的迭代器，指向新的位置（list 的前端）
        map[key] = cache.begin();
        return value; // 返回該 key 的 value
    }
    
    // put 函數：新增或更新一個 key-value，如果超出容量則淘汰最久未使用的元素
    void put(int key, int value) {
        // 如果 key 已存在於快取中，先將其移除
        if (map.find(key) != map.end()) {
            auto it = map[key];
            cache.erase(it);  // 移除原有的 key-value 對
        }
        // 如果快取容量已達上限，需要淘汰最久未使用的元素（list 的尾端）
        if (cache.size() == capacity) {
            auto last = cache.back(); // 取得尾端的元素
            int keyToRemove = last.first; // 待淘汰元素的 key
            cache.pop_back();             // 從 list 中移除該元素
            map.erase(keyToRemove);       // 從哈希表中刪除該 key 的記錄
        }
        // 將新的 key-value 對插入到 list 的前端（代表最新使用）
        cache.push_front({key, value});
        // 更新哈希表中該 key 對應的迭代器
        map[key] = cache.begin();
    }
    
private:
    int capacity;   // 快取的最大容量
    // 使用雙向鏈表來保存快取中的元素，前端為最近使用，後端為最久未使用
    std::list<std::pair<int, int>> cache;
    // 使用哈希表存儲 key 與其在 list 中的位置迭代器，便於快速查找和更新
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
};


