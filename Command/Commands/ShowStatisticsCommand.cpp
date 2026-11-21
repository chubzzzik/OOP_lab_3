#include"ShowStatisticsCommand.h"
#include"ShopFacade.h"

#include<memory>

ShowStatisticsCommand::ShowStatisticsCommand(std::shared_ptr<ShopFacade> facade):
        Command(facade){
}

void ShowStatisticsCommand::execute(){
    facade_->getStatistics();
}
