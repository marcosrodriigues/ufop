-- Database: Republica

-- DROP DATABASE "Republica";

CREATE DATABASE "Republica"
    WITH 
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'pt_BR.utf8'
    LC_CTYPE = 'pt_BR.utf8'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;

COMMENT ON DATABASE "Republica"
    IS 'Banco de Dados II
TP 02
Impelmentaçao do Banco de Dados fisico do minimundo Republica';

CREATE TABLE Pessoa (
    Id              INT             NOT NULL,
    Apelido         VARCHAR (50)    NOT NULL,
    Nome            VARCHAR (200)   NOT NULL,
    Foto            VARCHAR (200)   NOT NULL,
    Curso           INT                     ,
    Telefone        CHAR (14)               ,
    Nascimento      DATE            NOT NULL,
    Rua             VARCHAR (200)           ,
    Numero          VARCHAR (10)            ,
    Complemento     VARCHAR (30)            ,
    Bairro          VARCHAR (50)            ,
    Cidade          VARCHAR (100)           ,
    UF              CHAR (2)                ,
    CEP             CHAR (9)                ,
    Observacao      VARCHAR (500)           ,
    Liberado        BOOLEAN         DEFAULT TRUE,
    Excluido        BOOLEAN         DEFAULT FALSE,
    DataCadastro    TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE PessoaCelular (
    Id              INT             NOT NULL,
    Celular         VARCHAR (15)    NOT NULL
);

CREATE TABLE PessoaEmail (
    Id              INT             NOT NULL,
    Email           VARCHAR (50)    NOT NULL
);

CREATE TABLE Curso (
    Id              INT             NOT NULL,
    Curso           VARCHAR (50)    NOT NULL
);

CREATE TABLE TipoNaoAssociado (
    Id              INT             NOT NULL,
    Descricao       VARCHAR(50)     NOT NULL
);

CREATE TABLE NaoAssociado (
    Id              INT             NOT NULL,
    IdTipo          INT             NOT NULL,
    DataInclusao    TIMESTAMP       DEFAULT CURRENT_TIMESTAMP,
);

CREATE TABLE Associado (
    Id              INT             NOT NULL,
    Senha           VARCHAR(30)     NOT NULL
);

CREATE TABLE ExAluno (
    Id              INT             NOT NULL,
    Posicao			INT				NOT NULL,
    DataFormatura   DATE            NOT NULL
);

CREATE TABLE Homenageado (
    Id              INT             NOT NULL,
    Posicao			INT				NOT NULL,
    DataQuadrinho   DATE            NOT NULL
);

CREATE TABLE Morador (
    Id              INT             NOT NULL,
    DataIngresso    TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Presidencia (
    Id              INT             NOT NULL,
    Mes             INT             NOT NULL,
    Ano             INT             NOT NULL,
    IdMorador       INT             NOT NULL
);

CREATE TABLE PagamentoPresidencia (
    IdPresidencia   INT             NOT NULL,
    IdMorador       INT             NOT NULL,
    ValorPago       NUMERIC(5,2)    NOT NULL DEFAULT 0,
    DataPagamento   TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Despesa (
    Id              INT             NOT NULL,
    Descricao       VARCHAR (500)   NOT NULL
);

CREATE TABLE Receita (
    Id              INT             NOT NULL,
    Descricao       VARCHAR (500)   NOT NULL
);

CREATE TABLE PresidenciaDespesa (
    IdPresidencia   INT             NOT NULL,
    IdDespesa       INT             NOT NULL,
    Valor           NUMERIC(5,2)    NOT NULL,
    Pago            BOOLEAN         DEFAULT FALSE,
    DataPagamento   TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE PresidenciaReceita (
    IdPresidencia   INT             NOT NULL,
    IdReceita       INT             NOT NULL,
    Valor           NUMERIC(5,2)    NOT NULL,
    Origem          VARCHAR (300)   NOT NULL,
    DataReceita     TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Festa (
    Id              INT             NOT NULL,
    Nome            VARCHAR(50)     NOT NULL,
    ArteCamisa      VARCHAR(50)             ,
    Periodo         CHAR (4)                ,
    DataFesta       DATE            NOT NULL,
    Liberado        BOOLEAN         DEFAULT TRUE,
    Excluido        BOOLEAN         DEFAULT FALSE
);

CREATE TABLE Orcamento (
    Id              INT             NOT NULL,
    Item            VARCHAR (500)   NOT NULL
);

CREATE TABLE OrcamentoFesta (
    IdFesta         INT             NOT NULL,
    IdOrcamento     INT             NOT NULL,
    ValorUnitario   NUMERIC(5,2)    NOT NULL,
    Quantidade      INT             NOT NULL,
    Pago            BOOLEAN         DEFAULT FALSE,
    DataPagamento   TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE ContribuicaoFesta (
    IdAssociado     INT             NOT NULL,
    IdFesta         INT             NOT NULL,
    Valor           NUMERIC (5,2)   NOT NULL,
    DataPagamento   TIMESTAMP       DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE ResponsavelFesta (
    IdMorador       INT             NOT NULL,
    IdFesta         INT             NOT NULL
);

CREATE TABLE Noticia (
    Id              INT             NOT NULL,
    Titulo          VARCHAR (500)   NOT NULL,
    Chamada         VARCHAR (200)   NOT NULL,
    Texto           VARCHAR (8000)  NOT NULL,
    IdMorador       INT             NOT NULL,
    Data            TIMESTAMP       DEFAULT CURRENT_TIMESTAMP,
    Liberado        BOOLEAN         DEFAULT TRUE,
    Excluido        BOOLEAN         DEFAULT FALSE
    
);

CREATE TABLE Foto (
    Id              INT             NOT NULL,
    Local           VARCHAR (100)   NOT NULL,
    Descricao       VARCHAR (500)   NOT NULL,
    Data            TIMESTAMP       DEFAULT CURRENT_TIMESTAMP,
    Liberado        BOOLEAN         DEFAULT TRUE,
    Excluido        BOOLEAN         DEFAULT FALSE
);

CREATE TABLE FotoNoticia (
    IdFoto          INT             NOT NULL,
    IdNoticia       INT             NOT NULL
);

/*  Pessoa  */
ALTER TABLE Pessoa ADD CONSTRAINT pk_pessoa PRIMARY KEY (ID);
ALTER TABLE Pessoa ADD CONSTRAINT uk_apelido UNIQUE (Apelido);
ALTER TABLE Pessoa MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  PessoaCelular  */
ALTER TABLE PessoaCelular ADD CONSTRAINT pk_pessoaCelular PRIMARY KEY (ID, Celular);
ALTER TABLE PessoaCelular ADD CONSTRAINT fk_pessoaCelular FOREIGN KEY (ID) REFERENCES Pessoa (ID) ON DELETE CASCADE;
/*  PessoaEmail  */
ALTER TABLE PessoaEmail ADD CONSTRAINT pk_pessoaEmail PRIMARY KEY (ID, Email);
ALTER TABLE PessoaEmail ADD CONSTRAINT fk_pessoaEmail FOREIGN KEY (ID) REFERENCES Pessoa (ID) ON DELETE CASCADE;
/*  Curso  */
ALTER TABLE Curso ADD CONSTRAINT pkCurso PRIMARY KEY (ID);
ALTER TABLE Curso MODIFY COLUMN Id INT AUTO_INCREMENT;
ALTER TABLE Pessoa ADD CONSTRAINT fk_pessoaCurso FOREIGN KEY (Curso) REFERENCES Curso (ID);
/*  TipoNaoAssociado  */
ALTER TABLE TipoNaoAssociado ADD CONSTRAINT pkTipoNaoAssociado PRIMARY KEY (Id);
/*  NaoAssociado  */
ALTER TABLE NaoAssociado ADD CONSTRAINT pkNaoAssociado PRIMARY KEY (Id);
ALTER TABLE NaoAssociado ADD CONSTRAINT fkPessoaNaoAssociado FOREIGN KEY (Id) REFERENCES Pessoa (Id) ON DELETE CASCADE;
ALTER TABLE NaoAssociado ADD CONSTRAINT fkTipoNaoAssociado FOREIGN KEY (IdTipo) REFERENCES TipoNaoAssociado (Id);
/*  Associado  */
ALTER TABLE Associado ADD CONSTRAINT pkPessoaAssociado PRIMARY KEY (Id);
ALTER TABLE Associado ADD CONSTRAINT fkPessoaAssociado FOREIGN KEY (Id) REFERENCES Pessoa (Id) ON DELETE CASCADE;
/*  ExAluno  */
ALTER TABLE ExAluno ADD CONSTRAINT pkPessoaExAluno PRIMARY KEY (Id);
ALTER TABLE ExAluno ADD CONSTRAINT ukPosicao UNIQUE (Posicao);
ALTER TABLE ExAluno ADD CONSTRAINT fkPessoaExAluno FOREIGN KEY (Id) REFERENCES Associado (Id) ON DELETE CASCADE;
/*  Homenageado  */
ALTER TABLE Homenageado ADD CONSTRAINT pkPessoaHomenageado PRIMARY KEY (Id);
ALTER TABLE Homenageado ADD CONSTRAINT fkPessoaHomenageado FOREIGN KEY (Id) REFERENCES Associado (Id) ON DELETE CASCADE;
/*  Morador  */
ALTER TABLE Morador ADD CONSTRAINT pkPessoaMorador PRIMARY KEY (Id);
ALTER TABLE Morador ADD CONSTRAINT fkPessoaMorador FOREIGN KEY (Id) REFERENCES Associado (Id) ON DELETE CASCADE;
/*  Presidencia  */
ALTER TABLE Presidencia ADD CONSTRAINT fkPresidencia PRIMARY KEY (Id);
ALTER TABLE Presidencia ADD CONSTRAINT ukMesAno UNIQUE (Mes, Ano);
ALTER TABLE Presidencia ADD CONSTRAINT fkMoradorPresidencia FOREIGN KEY (IdMorador) REFERENCES Morador (Id);
ALTER TABLE Presidencia MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  PagamentoPresidencia  */
ALTER TABLE PagamentoPresidencia ADD CONSTRAINT fkPagamentoPresidencia PRIMARY KEY (IdPresidencia, IdMorador);
ALTER TABLE PagamentoPresidencia ADD CONSTRAINT fkPresidenciaPagamento FOREIGN KEY (IdPresidencia) REFERENCES Presidencia (Id) ON DELETE CASCADE;
ALTER TABLE PagamentoPresidencia ADD CONSTRAINT fkMoradorPagamento FOREIGN KEY (IdMorador) REFERENCES Morador (Id) ON DELETE CASCADE;
/*  Despesas  */
ALTER TABLE Despesa ADD CONSTRAINT pkDespesa PRIMARY KEY (Id);
ALTER TABLE Despesa MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  Receita  */
ALTER TABLE Receita ADD CONSTRAINT pkReceita PRIMARY KEY (Id);
ALTER TABLE Receita MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  PresidenciaDespesa  */
ALTER TABLE PresidenciaDespesa ADD CONSTRAINT pkPresidenciaDespesa PRIMARY KEY (IdPresidencia, IdDespesa);
ALTER TABLE PresidenciaDespesa ADD CONSTRAINT pkPDPresidencia FOREIGN KEY (IdPresidencia) REFERENCES Presidencia (Id) ON DELETE CASCADE;
ALTER TABLE PresidenciaDespesa ADD CONSTRAINT pkPDDespesa FOREIGN KEY (IdDespesa) REFERENCES Despesa (Id) ON DELETE CASCADE;
/*  `PresidenciaReceita  */
ALTER TABLE PresidenciaReceita ADD CONSTRAINT pkPresidenciaReceita PRIMARY KEY (IdPresidencia, IdReceita);
ALTER TABLE PresidenciaReceita ADD CONSTRAINT pkPRPresidencia FOREIGN KEY (IdPresidencia) REFERENCES Presidencia (Id) ON DELETE CASCADE;
ALTER TABLE PresidenciaReceita ADD CONSTRAINT pkPRReceita FOREIGN KEY (IdReceita) REFERENCES Receita (Id) ON DELETE CASCADE;
/*  Festa  */
ALTER TABLE Festa ADD CONSTRAINT pkFesta PRIMARY KEY (Id);
ALTER TABLE Festa MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  Orçamento  */
ALTER TABLE Orcamento ADD CONSTRAINT pkOrcamento PRIMARY KEY (Id);
ALTER TABLE Orcamento MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  OrçamentoFesta  */
ALTER TABLE OrcamentoFesta ADD CONSTRAINT pkOrcamentoFesta PRIMARY KEY (IdFesta, IdOrcamento);
ALTER TABLE OrcamentoFesta ADD CONSTRAINT fkOFFesta FOREIGN KEY (IdFesta) REFERENCES Festa (Id);
ALTER TABLE OrcamentoFesta ADD CONSTRAINT fkOFOrcamento FOREIGN KEY (IdOrcamento) REFERENCES Orcamento (Id);
/*  ContribuiçãoFesta  */
ALTER TABLE ContribuicaoFesta ADD CONSTRAINT pkCF PRIMARY KEY (IdAssociado, IdFesta);
ALTER TABLE ContribuicaoFesta ADD CONSTRAINT fkCFAssociado FOREIGN KEY (IdAssociado) REFERENCES Associado (Id) ON DELETE CASCADE;
ALTER TABLE ContribuicaoFesta ADD CONSTRAINT fkCFFesta FOREIGN KEY (IdFesta) REFERENCES Festa (Id) ON DELETE CASCADE;
/*  ResponsavelFesta  */
ALTER TABLE ResponsavelFesta ADD CONSTRAINT pkRF PRIMARY KEY (IdMorador, IdFesta);
ALTER TABLE ResponsavelFesta ADD CONSTRAINT fkRFMorador FOREIGN KEY (IdMorador) REFERENCES Morador (Id) ON DELETE CASCADE;
ALTER TABLE ResponsavelFesta ADD CONSTRAINT fkRFFesta FOREIGN KEY (IdFesta) REFERENCES Festa (Id) ON DELETE CASCADE;
/*  Noticia  */
ALTER TABLE Noticia ADD CONSTRAINT pkNoticia PRIMARY KEY (Id);
ALTER TABLE Noticia ADD CONSTRAINT fkNoticiaMorador FOREIGN KEY (IdMorador) REFERENCES Morador (Id);
ALTER TABLE Noticia MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  Foto  */
ALTER TABLE Foto ADD CONSTRAINT pkFoto PRIMARY KEY (Id);
ALTER TABLE Foto MODIFY COLUMN Id INT AUTO_INCREMENT;
/*  FotoNoticia  */
ALTER TABLE FotoNoticia ADD CONSTRAINT pkFN PRIMARY KEY (IdFoto, IdNoticia);
ALTER TABLE FotoNoticia ADD CONSTRAINT fkFNFoto FOREIGN KEY (IdFoto) REFERENCES Foto (Id) ON DELETE CASCADE;
ALTER TABLE FotoNoticia ADD CONSTRAINT fkFNNoticia FOREIGN KEY (IdNoticia) REFERENCES Noticia (Id) ON DELETE CASCADE;