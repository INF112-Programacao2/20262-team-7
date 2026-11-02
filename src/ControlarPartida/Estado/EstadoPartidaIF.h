#ifndef EstadoPartidaIF_h
#define EstadoPartidaIF_h

class EstadoPartidaIF {
public:
    virtual ~EstadoPartidaIF() = default;
    virtual void iniciarPartida() = 0;
    virtual void pausarPartida() = 0;
    virtual void retomarPartida() = 0;
    virtual void finalizarPartida() = 0;
};
#endif // EstadoPartidaIF_h 