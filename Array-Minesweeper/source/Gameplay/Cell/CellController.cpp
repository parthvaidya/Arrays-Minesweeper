#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/ServiceLocator.h"



namespace Gameplay
{
	namespace Cell
	{
		using namespace Global;
		using namespace Sound;


		CellController::CellController(sf::Vector2i grid_position)
		{
			cell_model = new CellModel(grid_position);
			cell_view = new CellView(this);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float cell_width, float cell_height)
		{
			cell_view->initialize(cell_width, cell_height);
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::flagCell()
		{
			if (ServiceLocator::getInstance()->getBoardService()->getBoardState() == Gameplay::Board::BoardState::COMPLETED)
			{
				cell_model->setCellState(CellState::FLAGGED);
				return;
			}

			switch (cell_model->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				cell_model->setCellState(CellState::HIDDEN);
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				cell_model->setCellState(CellState::FLAGGED);
				break;
			}
		}

		void CellController::openCell() //added
		{
			setCellState(CellState::OPEN);
		}

		bool CellController::canOpenCell()
		{
			return cell_model->getCellState() != CellState::FLAGGED && cell_model->getCellState() != CellState::OPEN;
		}

		
}