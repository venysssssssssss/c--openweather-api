# Projeto API de Clima em C++

Este projeto é uma aplicação em C++ que consome a API OpenWeatherMap para buscar e exibir dados meteorológicos. A estrutura do projeto separa as responsabilidades em diferentes módulos, tornando-o mais fácil de manter e expandir.

## Estrutura do Projeto

```
weather-api-cpp
├── src
│   ├── main.cpp               # Ponto de entrada da aplicação
│   ├── api
│   │   ├── weather_api.cpp    # Implementação da classe WeatherAPI
│   │   └── weather_api.h      # Declaração da classe WeatherAPI
│   ├── models
│   │   ├── weather_data.cpp   # Implementação da classe WeatherData
│   │   └── weather_data.h     # Declaração da classe WeatherData
│   └── utils
│       ├── http_client.cpp    # Implementação da classe HttpClient
│       └── http_client.h      # Declaração da classe HttpClient
├── build                      # Diretório de build (criado durante a compilação)
├── CMakeLists.txt             # Arquivo de configuração CMake
└── README.md                  # Documentação do projeto
```

## Dependências

- Compilador C++ com suporte a C++17 (g++ ou clang++)
- CMake (3.10 ou superior)
- libcurl (biblioteca de desenvolvimento)
- nlohmann_json (biblioteca para manipulação de JSON)
- Chave de API do OpenWeatherMap

## Instruções de Instalação

### 1. Instalar Dependências

```bash
# Para sistemas baseados em Debian/Ubuntu
sudo apt-get update
sudo apt-get install -y build-essential cmake libcurl4-openssl-dev nlohmann-json3-dev
```

### 2. Obter o Código Fonte

```bash
# Clonar o repositório (se estiver usando git)
git clone https://github.com/seuusuario/weather-api-cpp.git
cd weather-api-cpp

# Ou criar a estrutura do projeto manualmente
mkdir -p weather-api-cpp/src/{api,models,utils}
cd weather-api-cpp
```

### 3. Obter uma Chave de API do OpenWeatherMap

1. Visite [OpenWeatherMap](https://openweathermap.org/) e crie uma conta gratuita
2. Depois de fazer login, vá para a aba "API Keys"
3. Copie sua chave de API padrão ou crie uma nova
4. **Importante**: Chaves de API novas podem levar até 2 horas para serem ativadas

### 4. Compilar o Projeto

```bash
# Criar diretório de build
mkdir -p build
cd build

# Configurar com CMake
cmake ..

# Compilar o projeto
make
```

### 5. Executar a Aplicação

```bash
# No diretório build
./weather_app
```

## Guia de Uso

1. Quando solicitado, digite sua chave de API do OpenWeatherMap
2. Digite uma localização (ex: "São Paulo", "Rio de Janeiro,BR", "Nova York,US")
3. A aplicação mostrará a temperatura atual, umidade e condições meteorológicas

Exemplo:
```
Digite sua chave de API do OpenWeatherMap: SUA_CHAVE_API_AQUI
Digite uma localização (nome da cidade ou cidade,código do país): São Paulo,BR

Clima para São Paulo,BR:
Temperatura: 23.5°C
Umidade: 70%
Condições: céu limpo
```

## Solução de Problemas

### Problemas com a Chave de API

- **Erro: "API key has been disabled"** - Sua chave de API pode ainda estar sendo ativada. Chaves novas podem levar até 2 horas para se tornarem ativas.
- **Erro: "Invalid API key"** - Verifique sua chave de API em busca de erros de digitação.

### Problemas com a Localização

- **Erro: "city not found"** - Tente um formato diferente (ex: "São Paulo,BR" em vez de apenas "São Paulo").
- Use localizações específicas adicionando o código do país (ex: "Rio de Janeiro,BR").

### Problemas de Compilação

- **Dependências ausentes** - Certifique-se de que todos os pacotes necessários estão instalados.
- **Erros de compilação** - Verifique se seu compilador suporta C++17.

## Expandindo o Projeto

- Adicione suporte para previsões meteorológicas usando os endpoints de previsão do OpenWeatherMap
- Implemente cache para reduzir chamadas de API
- Adicione uma interface gráfica de usuário
- Dê suporte a outros provedores de clima

## Licença

Este projeto é open source e disponível sob a Licença MIT.