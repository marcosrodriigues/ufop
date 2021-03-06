import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './section/header/header.component';
import { IndexComponent } from './page/index/index.component';
import { FooterComponent } from './section/footer/footer.component';
import { SobreComponent } from './page/sobre/sobre.component';
import { LoginComponent } from './page/login/login.component';
import { SearchComponent } from './page/search/search.component';
import { RepublicDetailComponent } from './page/republic-detail/republic-detail.component';
import { ProfileComponent } from './page/profile/profile.component';
import { MyRepublicComponent } from './page/my-republic/my-republic.component';
import { InventoryComponent } from './page/inventory/inventory.component';

import { HttpClientModule, HTTP_INTERCEPTORS } from '@angular/common/http';
import { FormsModule } from '@angular/forms';

import { CookieService } from 'ngx-cookie-service';
import { MyHttpInterceptor } from './http-interceptor';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';

import {
  MatExpansionModule,
  MatButtonModule
} from '@angular/material';
import { AdicionarUniversidadeComponent } from './modal/adicionar-universidade/adicionar-universidade.component';
import { VincularRepublicaComponent } from './modal/vincular-republica/vincular-republica.component';
import { TermoDeUsoComponent } from './modal/termo-de-uso/termo-de-uso.component';
import { ProfileEstudanteComponent } from './component/profile-estudante/profile-estudante.component';
import { ProfileRepublicaComponent } from './component/profile-republica/profile-republica.component';
import { ExcluirContaComponent } from './modal/excluir-conta/excluir-conta.component';
import { MoradoresComponent } from './modal/moradores/moradores.component';
import { ChartComponent } from './component/chart/chart.component';
import { DescricaoPersonalidadeComponent } from './component/descricao-personalidade/descricao-personalidade.component';
import { ChartColumnCompareComponent } from './component/chart-column-compare/chart-column-compare.component';
import { TableCompareComponent } from './component/table-compare/table-compare.component';
import { ChartDifferenceComponent } from './component/chart-difference/chart-difference.component';
import { ComoUsarComponent } from './page/como-usar/como-usar.component';
import { EsqueciMinhaSenhaComponent } from './modal/esqueci-minha-senha/esqueci-minha-senha.component';
import { ContatoComponent } from './modal/contato/contato.component';
import { AdminIndexComponent } from './admin/page/admin-index/admin-index.component';
import { AdminInfoCadastroComponent } from './admin/components/admin-info-cadastro/admin-info-cadastro.component';
import { AdminListaRepublicaComponent } from './admin/components/admin-lista-republica/admin-lista-republica.component';
import { AdminCadaRepublicaListaComponent } from './admin/components/admin-cada-republica-lista/admin-cada-republica-lista.component';
import { RecomendarComponent } from './admin/modal/recomendar/recomendar.component';
import { AdminListaEstudanteSemRepublicaComponent } from './admin/components/admin-lista-estudante-sem-republica/admin-lista-estudante-sem-republica.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    IndexComponent,
    FooterComponent,
    SobreComponent,
    LoginComponent,
    SearchComponent,
    RepublicDetailComponent,
    ProfileComponent,
    MyRepublicComponent,
    InventoryComponent,
    AdicionarUniversidadeComponent,
    VincularRepublicaComponent,
    TermoDeUsoComponent,
    ProfileEstudanteComponent,
    ProfileRepublicaComponent,
    ExcluirContaComponent,
    MoradoresComponent,
    ChartComponent,
    DescricaoPersonalidadeComponent,
    ChartColumnCompareComponent,
    TableCompareComponent,
    ChartDifferenceComponent,
    ComoUsarComponent,
    EsqueciMinhaSenhaComponent,
    ContatoComponent,
    AdminIndexComponent,
    AdminInfoCadastroComponent,
    AdminListaRepublicaComponent,
    AdminCadaRepublicaListaComponent,
    RecomendarComponent,
    AdminListaEstudanteSemRepublicaComponent,
    
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    BrowserAnimationsModule,
    MatExpansionModule,
    MatButtonModule
  ],
  providers: [
    CookieService,
    {
      provide: HTTP_INTERCEPTORS,
      useClass: MyHttpInterceptor,
      multi: true
    }
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
