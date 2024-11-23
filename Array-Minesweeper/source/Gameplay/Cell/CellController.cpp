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
}