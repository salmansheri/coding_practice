
# Constant Time Complexity

## 1. O(1):

* No loop no conditions. 
Ex: 
Sum of numbers from 1 to N:

```cpp
int n; 
cin>>n; 
int ans = n * (n+1)/2
```

## Constant Time complexity
### Graph: 


![[Screenshot from 2024-09-19 11-25-50.png]]


# Linear Time Complexities:

## O(n):

Ex:

1. N Factorial:

```cpp
int fact = 1; 
for(int i = 1; i<=n; i++) {
fact *= 1
}
```

2. Nth Fibonacci - DP:

```cpp
for(int i = 2; i<=n; i++) {
	dp[i] = dp[i - 1] + dp[i-2]; 
}
```

3. Kadane's Algorithm 

```cpp
int currSum = 0;
int ans = INT_MIN; 

for (int i = 0; i<n; i++) {
currSum += arr[i]; 
ans = max(currSum, ans); 
currSum = currSum < 0 ? 0: currSum; 

}
```

