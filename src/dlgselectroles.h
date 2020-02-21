#ifndef DLGROLESSELECTION_H
#define DLGROLESSELECTION_H

#include <QDialog>

#include "rolesmodel/rolesmodel.h"

#include <shv/iotqt/rpc/clientconnection.h>

namespace Ui {
class DlgRolesSelection;
}

class DlgSelectRoles : public QDialog
{
	Q_OBJECT

public:
	explicit DlgSelectRoles(QWidget *parent);
	~DlgSelectRoles();

	void init(shv::iotqt::rpc::ClientConnection *rpc_connection, const std::string &acl_etc_roles_node_path, const std::vector<std::string> &roles);

	std::vector<std::string> selectedRoles();
	void setUserRoles(const std::vector<std::string> &roles);


private:
	std::vector<std::string> m_userRoles;
	RolesTreeModel *m_rolesModel = nullptr;

	Ui::DlgRolesSelection *ui;
};

#endif // DLGROLESSELECTION_H