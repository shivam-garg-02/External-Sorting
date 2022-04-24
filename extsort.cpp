#include <bits/stdc++.h>
using namespace std;

void pass0(vector<int>& records, int num_buffer_pages, int num_records_page, int num_pages)
{
    // int page_index = num_records_page;
    int run_index = num_records_page*num_buffer_pages;

    int num_runs = num_pages / num_buffer_pages;
    if (num_pages % num_buffer_pages != 0) num_runs++;

    for(int i = 0; i < num_runs; i++){
        if (i != (num_runs-1))
            sort(records.begin()+(i*run_index), records.begin()+((i+1)*run_index));
        else
            sort(records.begin()+(i*run_index), records.end());
    }
}

void remaining_passes(vector<int>& records, int num_buffer_pages, int num_records_page, int num_pages)
{
    // int page_index = num_records_page;
    int prev_run_index = num_records_page*num_buffer_pages;

    int prev_num_runs = num_pages / num_buffer_pages;
    if (num_pages % num_buffer_pages != 0) prev_num_runs++; 

    if (prev_num_runs == 1) return;

    int curr_num_runs = prev_num_runs / (num_buffer_pages-1);
    if (prev_num_runs % (num_buffer_pages-1) != 0) curr_num_runs++;

    int curr_run_index = prev_run_index * (num_buffer_pages - 1);

    while(true){
        if (curr_num_runs == 1){
            sort(records.begin(), records.end());
            break;
        }

        for(int i = 0; i < curr_num_runs; i++){
            if (i != (curr_num_runs - 1))
                sort(records.begin()+(i*curr_run_index), records.begin()+((i+1)*curr_run_index));
            else
                sort(records.begin()+(i*curr_num_runs), records.end());
        }

        prev_num_runs = curr_num_runs;
        prev_run_index = curr_run_index;

        curr_num_runs = prev_num_runs / (num_buffer_pages-1);
        if (prev_num_runs % (num_buffer_pages-1) != 0) curr_num_runs++;   

        int curr_run_index = prev_run_index * (num_buffer_pages - 1);  
    }
}

void sort_a_run(vector<int>& records, int run_number, int curr_run_index, int num_pages, int prev_run_index, int num_buffer_pages){
    vector<int> sorted_run;
    int ptr[num_buffer_pages-1] = {0};
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_buffer_pages;
    int num_records_page;
    int total_records;
    cin >> num_buffer_pages >> num_records_page >> total_records;

    vector<int> records(total_records);
    for(int i = 0; i < total_records; i++){
        cin >> records[i];
    }

    int num_pages = records.size() / num_records_page;
    if (records.size() % num_records_page != 0) num_pages++;

    pass0(records, num_buffer_pages, num_records_page, num_pages);

    remaining_passes(records, num_buffer_pages, num_records_page, num_pages);

    for(int i = 0; i < records.size(); i += num_records_page){
        for(int j = 0; j < num_records_page; j++){
            cout << records[i+j] << " ";
        }
        cout << endl;
    }
    return (0);
}