	struct pre_activity就是某vertex的前一個activity，裡面的vertex就是前一個vertex，activity
就是要經由哪個activity，value就是經由這個activity所需的cost，pre_activity就是前一個vertex的前一個activity
；struct aoe就是所有vertex，裡面存這個vertex的所有pre_activity。
	函式compute用來計算所有ee[]，函式computle用來計算所有le[]，函式computee用來計算所有e[]，函式computel用來計算所有l[]
再透過l[]跟e[]算出slack[]，當slack == 0代表此為crtical network，最後再依格式輸出。