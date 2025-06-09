// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column
// 2023/12/13

class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int[] rows = new int[grid.length];
        int[] cols = new int[grid[0].length];

        int count;

        for (int i = 0; i < grid.length; ++i) {
            count = 0;
            for (int j = 0; j < grid[0].length; ++j) {
                count += grid[i][j];
            }
            rows[i] = (count << 1) - grid.length;
        }
        
        for (int i = 0; i < grid[0].length; ++i) {
            count = 0;
            for (int j = 0; j < grid.length; ++j) {
                count += grid[j][i];
            }
            cols[i] = (count << 1) - grid[0].length;
        }

        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                grid[i][j] = rows[i] + cols[j];
            }
        }

        rows = null;
        cols = null;
        System.gc();
        
        return grid;
    }
}