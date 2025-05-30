#include "AForm.h"
#include <ctime>
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        
        const std::string get_name() const;
        void execute(const Bureaucrat bureaucrat) const;
};


