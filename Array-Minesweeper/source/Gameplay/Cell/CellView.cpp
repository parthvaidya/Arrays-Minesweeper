#include "../../header/Gameplay/Cell/CellView.h"

#include <iostream>

#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"



public class CellView {
    private Button cell_button;
    private final float tile_size = 32;

    // Lifecycle method: Initialize
    public void initialize() {
        float size = tile_size * 3;
        initializeButtonImage(size, size);
    }

    // Method to initialize the button's size and properties
    private void initializeButtonImage(float width, float height) {
        cell_button = new Button();  // Assuming Button is a custom class
        cell_button.setWidth(width);
        cell_button.setHeight(height);
        // Add additional properties or styles here if needed
    }

    // Lifecycle method: Update
    public void update(float deltaTime) {
        if (cell_button != null) {
            cell_button.update(deltaTime); // Delegates to button's update logic
        }
    }

    // Lifecycle method: Render
    public void render() {
        if (cell_button != null) {
            cell_button.render(); // Delegates to button's render logic
        }
    }
}