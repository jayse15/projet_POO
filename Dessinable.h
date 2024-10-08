#pragma once

class SupportADessin;

class Dessinable {
    public:
        virtual void dessine_sur(SupportADessin&) = 0;

        virtual ~Dessinable() = default;
        // On peut en principe copier et déplacer les objets dessinables
        Dessinable(Dessinable const&)            = default;
        Dessinable& operator=(Dessinable const&) = default;
        Dessinable(Dessinable&&)                 = default;
        Dessinable& operator=(Dessinable&&)      = default;
        Dessinable() = default;
};
