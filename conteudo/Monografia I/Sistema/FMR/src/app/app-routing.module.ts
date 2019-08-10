import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { IndexComponent } from './page/index/index.component';
import { SobreComponent } from './page/sobre/sobre.component';
import { LoginComponent } from './page/login/login.component';
import { SearchComponent } from './page/search/search.component';
import { RepublicDetailComponent } from './page/republic-detail/republic-detail.component';
import { ProfileComponent } from './page/profile/profile.component';
import { MyRepublicComponent } from './page/my-republic/my-republic.component';
import { InventoryComponent } from './page/inventory/inventory.component';


const routes: Routes = [
  { path: '', component: IndexComponent },
  { path: 'sobre', component: SobreComponent },
  { path: 'login', component: LoginComponent },
  { path: 'search', component: SearchComponent },
  { path: 'republica/:id', component: RepublicDetailComponent},
  { path: 'profile', component: ProfileComponent },
  { path: 'minha-republica', component: MyRepublicComponent },
  { path: 'inventario', component: InventoryComponent }


];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
