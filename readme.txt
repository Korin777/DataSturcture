第一題:
	遞迴函式ackerman吃兩個int m和n，當m等於0回傳n+1，當n等於0回傳ackerman(m-1,1)，當m和n都不等於0回傳ackerman(-1,1)。主程式讀入m和n在輸出ac
kerman(m,n)。
第二題:
	遞迴函式powerset吃四個參數int a(用來紀錄式遞幾個字串)、bool[](用來記錄是否印出該字串)、int record(字串總長度)、string c[](輸入的字串)，
函式會先將b[a]都設成false(表示不印出該字串),然後跑powerset(a+1,b,record,c)一直遞迴下去直到字串陣列c的尾巴才return並印出該次集合，每次跑powerset
都是先設成false而return回來後才設成true(表示把它印出)，而函數跑完就會印出所有集合，有點像左邊是0右邊是1的二元樹。而主程式則讀取一行存進一行在用
一個字串陣列以空個存取每個字串在跑powerset。
