動態規劃是分治法的延伸。當遞迴分割出來的問題，一而再、再而三出現，就運用記憶法儲存這些問題的答案，避免重複求解，以空間換取時間。

解決的問題:最佳化問題和計數問題,最佳化問題通常要在許多可行解裡面找出一個「最好的答案」，比方說，找零錢問題，我們的目標就是要找出「使用錢幣最少」的找錢方案。此時「最小化使用的錢幣總數」就是這個最佳化問題的目標函數。另一方面，計數問題所求的，並非是最好的答案，反而要全面性的計算有幾種可能的答案或其加權總數。比方說機器人走路問題，就是一個典型的計數問題。絕大多數的計數問題可以使用數學方法來解決。但是，當參數一多的時候，動態規劃的解題觀念就派上用場啦！



解法分為兩種:

1.top-down:遞迴＋記憶化搜索 (define a state->instead of starting from the base state , we ask our answer from the states that can reach the destination state)。好處:一是只需要關心遞迴的部份、不需要擔心計算順序，二來只需要計算真正需要計算的狀態，有些狀態不需要去計算它。

2.bottom-up:填表法(define a state-> starts its transition from the bottom-most base case dp[0] and reaches its destination state dp[n]) 


: )
