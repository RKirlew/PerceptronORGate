#include <iostream>
#include <vector>

int activate(float aWeightedSum); 

int main() {
    float weightedSum;
    bool trainingComplete = false;
    float bias = 0.0f;
    float learningRate = 0.1f;
    float weight = 0.3f;
    float weight2 = 0.2f;

    std::vector<std::vector<int>> trainingData = {
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 0},
        {0, 1, 1}
    };

    while (!trainingComplete) {
        trainingComplete = true;

        for (const auto& sample : trainingData) {
        	
            int input1 = sample[0];
            int input2 = sample[1];
            int target = sample[2];
		
            
            weightedSum = input1 * weight + input2 * weight2 + bias;

            int output = activate(weightedSum);
            float error = target - output;

            if (error != 0) {
                trainingComplete = false;
                // Update weights using the perceptron learning rule
                weight += learningRate * error * input1;
                weight2 += learningRate * error * input2;
                bias += learningRate * error; // Bias update
            }

            std::cout << "Inputs: [" << input1 << ", " << input2 << "], "
                      << "Weighted Sum: " << weightedSum
                      << ", Output: " << output
                      << ", Target: " << target
                      << ", Error: " << error << std::endl;
        }
        std::cout << "--- End of Epoch ---" << std::endl;
    }

    std::cout << "Training complete!" << std::endl;
    std::cout << "Final weights: weight1 = " << weight << ", weight2 = " << weight2 << ", bias = " << bias << std::endl;

    return 0;
}

int activate(float aWeightedSum) {
    return (aWeightedSum >= 0) ? 1 : 0;
}
