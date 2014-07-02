#include "component/ComponentFactory.h"

#include "component/controller/CodeController.h"
#include "component/view/CodeView.h"
#include "component/view/ViewLayout.h"
#include "gui/GuiFactory.h"

std::shared_ptr<ComponentFactory> ComponentFactory::create(
	GuiFactory* guiFactory,
	ViewLayout* viewLayout,
	std::shared_ptr<CodeAccess> codeAccess,
	std::shared_ptr<GraphAccess> graphAccess)
{
	std::shared_ptr<ComponentFactory> ptr(new ComponentFactory());
	ptr->m_guiFactory = guiFactory;
	ptr->m_viewLayout = viewLayout;
	ptr->m_codeAccess = codeAccess;
	ptr->m_graphAccess = graphAccess;
	return ptr;
}

ComponentFactory::~ComponentFactory()
{
}

std::shared_ptr<Component> ComponentFactory::createCodeComponent()
{
	std::shared_ptr<View> view = m_guiFactory->createCodeView(m_viewLayout);
	std::shared_ptr<Controller> controller = std::make_shared<CodeController>();

	std::shared_ptr<Component> component = std::make_shared<Component>(view, controller);
	return component;
}

ComponentFactory::ComponentFactory()
{
}
