#include <cstdio>

class Queens {
    public:

        Queens() : count(0) {
            for (int i = 0; i < 8; i++)
                col_free[i] = true;
            for (int i = 0; i < 15; i++)
                upward_free[i] = true, downward_free[i] = true;
        }
        
        bool is_solved() const {
            return count == 8;
        }

        void print() const {
            for (int i = 0; i < 7; i++)
                printf("%d ", queen_in_row[i]);
            printf("%d\n", queen_in_row[7]);
        }

        bool unguarded(int col) const {
            return col_free[col] && upward_free[count + col] && downward_free[count - col + 7];
        }

        void insert(int col) {
            queen_in_row[count] = col + 1;
            col_free[col] = false;
            upward_free[count + col] = false;
            downward_free[count - col + 7] = false;
            count++;
        }

        void remove(int col) {
            count--;
            col_free[col] = true;
            upward_free[count + col] = true;
            downward_free[count - col + 7] = true;
        }

    private:

        int count;
        bool col_free[8];
        bool upward_free[15];
        bool downward_free[15];
        int queen_in_row[8];
};

void solve_from(Queens &configuration) {
    if (configuration.is_solved()) configuration.print();
    else
        for (int col = 0; col < 8; col++) {
            if (configuration.unguarded(col)) {
                configuration.insert(col);
                solve_from(configuration);
                configuration.remove(col);
            }
        }
}

int main() {
    Queens configuration;
    solve_from(configuration);
    return 0;
}

