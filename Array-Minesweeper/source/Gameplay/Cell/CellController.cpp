#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/ServiceLocator.h"



public class CellController {
    private CellView cellView;

    // Lifecycle method: Initialize
    public void initialize() {
        cellView = new CellView();
        cellView.initialize();
    }

    // Lifecycle method: Update
    public void update(float deltaTime) {
        if (cellView != null) {
            cellView.update(deltaTime);
        }
    }

    // Lifecycle method: Render
    public void render() {
        if (cellView != null) {
            cellView.render();
        }
    }

    private CellView cellView;
    private CellModel cellModel;

    // Constructor
    public CellController() {
        cellModel = new CellModel(); // Initialize the model
    }

    // Lifecycle method: Initialize
    public void initialize() {
        cellView = new CellView();
        cellView.initialize();
    }

    // Getter and Setter for CellValue
    public CellModel.CellValue getCellValue() {
        return cellModel.getCellValue();
    }

    public void setCellValue(CellModel.CellValue cell_value) {
        cellModel.setCellValue(cell_value);
    }

    // Getter and Setter for CellState
    public CellModel.CellState getCellState() {
        return cellModel.getCellState();
    }

    public void setCellState(CellModel.CellState cell_state) {
        cellModel.setCellState(cell_state);
    }

    // Lifecycle method: Update
    public void update(float deltaTime) {
        if (cellView != null) {
            cellView.update(deltaTime);
        }
    }

    // Lifecycle method: Render
    public void render() {
        if (cellView != null) {
            cellView.setCellTexture(cellModel.getCellState(), cellModel.getCellValue());
            cellView.render();
        }
    }
}