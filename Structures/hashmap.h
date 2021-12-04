#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/*
    This class is an implementation of a hashmap for string types.

    It features functions to remove, insert, and check for the existance of items. The underlying structures are created with STL containers.
*/
class HashmapStr
{
public:
    HashmapStr(size_t size) : buckets(size)
    {}

    //Inserts the string 'val' into the hashmap.
    //O(1)
    void Insert(std::string val)
    {
        int index = strHashFunc(val, buckets.size());
        buckets[index].push_back(val);
    }

    //Removes the string 'val' from the hashmap.
    //Returns a boolean indicating if the operation was successful or not.
    bool Remove(std::string val)
    {
        int index = strHash(val);
        auto& bucket = buckets[index];

        if (bucket.size() == 0)
        {
            return false;
        }

        else
        {
            auto it = std::find(bucket.begin(), bucket.end(), val);

            if (it != bucket.end())
            {
                buckets[index].erase(it);
                return true;
            }

            return false;
        }
    }

    //Returns a boolean indicating if 'val' is contained in the hashmap.
    bool Exists(std::string val)
    {
        int index = strHash(val);
        const auto& bucket = buckets[index];

        if (bucket.size() == 0)
        {
            return false;
        }
        else
        {
            return std::find(bucket.begin(), bucket.end(), val) != bucket.end();
        }
    }

private:
    std::vector<std::list<std::string>> buckets;

    int strHash(std::string str)
    {
        return std::hash<std::string>{}(str) % buckets.size();
    }
};

int main() {
    HashmapStr h(10);
    h.Insert("Hello");
    h.Insert("There");
    h.Insert("Hello");
    h.Insert("No way");
    h.Remove("Hello");

    std::cout << h.Exists("Hello");
}