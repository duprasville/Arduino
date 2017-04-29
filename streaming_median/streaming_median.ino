void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


class DynamicArray
{
public:
    void insert(unsigned long num)
    {
        if(((minHeap.size() + maxHeap.size()) & 1) == 0)
        {
            if(maxHeap.size() > 0 && num < maxHeap[0])
            {
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(), maxHeap.end(), less());

                num = maxHeap[0];

                pop_heap(maxHeap.begin(), maxHeap.end(), less());
                maxHeap.pop_back();
            }

            minHeap.push_back(num);
            push_heap(minHeap.begin(), minHeap.end(), greater());
        }
        else
        {
            if(minHeap.size() > 0 && minHeap[0] < num)
            {
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater());

                num = minHeap[0];

                pop_heap(minHeap.begin(), minHeap.end(), greater());
                minHeap.pop_back();
            }

            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end(), less());
        }
    }

    unsigned long getMedian()
    {
        unsigned long size = minHeap.size() + maxHeap.size();
        if(size == 0)
            throw exception("No numbers are available");

        unsigned long median = 0;
        if(size & 1 == 1)
            median = minHeap[0];
        else
            median = (minHeap[0] + maxHeap[0]) / 2;

        return median;
    }

private:
    vector minHeap;
    vector maxHeap;
};
