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
    ProfileComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
