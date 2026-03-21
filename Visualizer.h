#include <iostream>
#include <vector>
#include <raylib.h>
#include <raymath.h>

class Visualizer {
private:
    int screen_width, screen_height;
    bool initialized = false;
    Font Arial;
    std::vector<int> global_dp;
    std::string Description;
    struct {
        std::pair<int, int> i;
        std::pair<int, int> j;
    } printing_range;
    struct {
        int i;
        int j;
    } range_length; 

    float box_size, box_dist, font_size;
    
    void loadFont();
    void DrawArrow(Vector2 start, Vector2 end, Color color);

public:
    void init1D(const std::vector<int>& dp, std::pair<int, int> range);
    void update1D(const std::vector<int>& dp, std::vector<int>& prev, std::vector<int>& cur);

    void init2D(const std::vector<std::vector<int>>& dp, std::pair<int, int> range_i, std::pair<int, int> range_j);
    void update2D(const std::vector<std::vector<int>>& dp, std::vector<std::pair<int, int>>& prev, std::vector<std::pair<int, int>>& cur);

    template<typename... Args>
    void updateDescription(std::string str, Args... args){
        Description = TextFormat(str.c_str(), args...);
    }

    void stop();
};

// Ready to use singleton object.
extern Visualizer viz;

void init(std::vector<int>& dp, std::pair<int, int> range);
void Visualize(std::vector<int>& dp, std::vector<int> prev, std::vector<int> cur);

void init(std::vector<std::vector<int>>& dp, std::pair<int, int> range_i, std::pair<int, int> range_j);
void Visualize(std::vector<std::vector<int>>& dp, std::vector<std::pair<int, int>> prev, std::vector<std::pair<int, int>> cur);

template<typename... Args>
void Describe(std::string description, Args... args) {
    viz.updateDescription(description, args...);
};

void stop();