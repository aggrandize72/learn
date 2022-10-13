#include <stdio.h>
#include <limits.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main (){
    int a[]={1,2,4};
    int b[]={3,5,6};
    double c = findMedianSortedArrays(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int));
    printf("%f",c);
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n = nums1Size, m = nums2Size;
    //确保第一个数组最短。
    if (n > m){
        return findMedianSortedArrays(nums2, m,  nums1, n);
    }
    int Lmax1,Lmax2,Rmin1,Rmin2,array1,array2,head = 0,tail = 2 * n;
    while (head <= tail){
        array1 = (head + tail) / 2;
        array2 = n + m - array1;

        Lmax1 = (array1 == 0) ? INT_MIN : nums1[(array1 - 1) / 2];
        Rmin1 = (array1 == 2 * n) ? INT_MAX : nums1[array1 / 2];
        Lmax2 = (array2 == 0) ? INT_MIN : nums2[(array2 - 1) / 2];
        Rmin2 = (array2 == 2 * m) ? INT_MAX : nums2[array2 / 2];

        if (Lmax1 > Rmin2){
            tail = array1 - 1;
        }else if (Lmax2 > Rmin1){
            head = array1 + 1;
        }else {
            break;
        }
    }
    return  ( max(Lmax1,Lmax2) + min(Rmin1,Rmin2) ) / 2.0;
}

/*

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n = nums1Size, m = nums2Size;
    //确保第一个数组最短。
    if (n > m){
        return findMedianSortedArrays(nums2, m, nums1, n);
    }
//    int Lmax1 = nums1[(n - 1) / 2],Rmin1 = nums1[n / 2];
//    int Lmax2 = nums2[(m - 1) / 2],Rmin2 = nums2[m / 2];
    int Lmax1,Lmax2,Rmin1,Rmin2,array1,array2,head = 0,tail = n;
    while (head <= n){
        array1 = head + tail ;
        array2 = n + m - array1;

        Lmax1 = (array1 == 0) ? INT_MIN : nums1[(array1 - 1) / 2];
        Rmin1 = (array1 == 2*n) ? INT_MAX : nums1[array1 / 2];
        Lmax2 = nums2[(array2 - 1) / 2];
        Rmin2 = nums2[array2 / 2];

        if (Lmax1 > Rmin2){
            tail = (array1 + 1) / 2;
        }else if (Lmax2 > Rmin1){
            head = (array1 + 1) / 2;
        }else {
            break;
        }
    }
    return  ( max(Lmax1,Lmax2) + min(Rmin1,Rmin2) ) / 2.0;
}
*/




/*

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double a;
    if (nums1Size == 0 ){
        if(nums2Size % 2 ){
            return (double)nums2[nums2Size / 2];
        }else{
            return (nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
        }
    }else if(nums2Size == 0 ){
        if(nums1Size % 2 ){
            return (double)nums1[nums1Size / 2];
        }else{
            return (nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2.0;
        }
    }
    int Size = nums1Size + nums2Size,k; // k为需要排除的元素个数。
    int num1 = 0,num2 = 0;
    //总数为Size
    //当Size为奇数，则总共需要排除Size / 2 个元素
    //当Size为偶数，则总共需要排除Size / 2 - 1个元素
    if (Size % 2){
        k = Size / 2;
    }else{
        k = Size / 2 - 1;
    }
    int k2 = k/2;
    //正常情况时的代码
    //采用二分法，每次需要排除一半的个数k2,剩下k -= k2个个数
    while ( k != 1) {
        k -= k2;
        if(k2 >= nums1Size - num1 ){
            k2 = nums1Size - num1-1;
            if (nums1[k2] > nums2[k - k2 - 1]){
                num2 = k - k2 - 1;
            }else if(Size % 2){
                return (double)nums2[k - k2 - 1];
            }else{
                return (nums2[k - k2] + nums2[k - k2 - 1])/2.0;
            }
        }else if (k2 >= nums2Size - num2){
            k2 = nums2Size - num2 -1;
            if (nums2[k2] > nums1[k - k2 - 1]){
                num1 = k - k2 - 1;
            }else if(Size % 2){
                return (double)nums1[k - k2 - 1];
            }else{
                return (nums1[k - k2] + nums1[k - k2 - 1])/2.0;
            }
        }else if (nums1[num1+k2] > nums2[num2+k2]){
            num2 += k2;
        }else{
            num1 += k2;
        }
        k2 = k / 2;
    }
    if (Size % 2){
        if(nums1[num1] > nums2[num2]){
            if(num2 == nums2Size - 1)
                return (double)nums1[num1];
            num2 ++;
        }else{
            if(num1 == nums1Size - 1)
                return (double)nums2[num2];
            num1 ++;
        }
        if(nums1[num1] > nums2[num2]){
            return (double)nums2[num2];
        }else{
            return (double)nums1[num1];
        }
    }else {
        if(nums1[num1] > nums2[num2]){
            if(num2 == nums2Size-1) {
                return (nums1[num1] + nums1[num1 + 1])/2.0;
            }
            num2++;
        }else{
            if(num1 == nums1Size-1) {
                return (nums2[num2] + nums2[num2 + 1])/2.0;
            }
            ++num1;
        }
        if(nums1[num1] > nums2[num2]){
            a = nums2[num2];
            if(num2 == nums2Size-1) {
                a += nums1[num1];
                return a/2;
            }
            num2++;
        }else{
            a = nums1[num1];
            if(num1 == nums1Size-1) {
                a += nums2[num2];
                return a/2;
            }
            ++num1;
        }
        if(nums1[num1] > nums2[num2]){
            a += nums2[num2];
        }else{
            a += nums1[num1];
        }
        return a/2;
    }
}
*/
