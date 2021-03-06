/*************************************************************************
	> File Name: w8-5-6.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, November 21, 2014 PM07:32:02 CST
 ************************************************************************/

template <class Record>
void quick_sort(Record *startPointer, Record *endPointer) {
    if (startPointer != endPointer) {
        Record *low = startPointer, *high = endPointer, temp = *startPointer;
        high--;
        while (low != high) {
            while (low < high && *high > temp) high--;
            if (low != high) *low++ = *high;
            while (low < high && *low < temp) low++;
            if (low != high) *high-- = *low;
        }
        *low = temp;
        quick_sort(startPointer, low--);
        low++;
        quick_sort(++low, endPointer);
    }
}

